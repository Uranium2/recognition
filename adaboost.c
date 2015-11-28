# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <dirent.h>
# include <math.h>

# include "integral_img.h"
# include "adaboost.h"
# include "quick_sort.h"
# include "grey_scale.h"
# include "sdl_stuff.h"
# include "haar.h"

static int compute_threshold(struct ada_feat *af);
static int sp(struct ada_feat *af, int threshold);
static int sm(struct ada_feat *af, int threshold);
static int compute_weakclass(int threshold, int polarity, int features);

int nb_feat = 136656;
int nb_neg;
int nb_pos;

struct image *prepare_tab_image( int nb) {

	struct image *tab_image = calloc(nb, sizeof(struct image));

	int i = 0;
	int** M; //tableau intégral image

	DIR* rep = NULL;
	struct dirent* file = NULL;
	rep = opendir("./pos");

	if (rep == NULL) {
		printf("Erreur lors de la lecture du dossier pos");
		exit(1);
	}

	while((file = readdir(rep)) != NULL) {
		if(file->d_name[0] != '.' && file->d_name[1] != '.') {
			char src[256] = "./pos/";
			char *name = strcat(src, file->d_name);
			SDL_Surface *img;
			img = load_image(name);
			grey_scale(img);
			M = integral_img(img);

			struct HaarF *feat = malloc(sizeof(struct HaarF));
			HaarFeatures(M, feat);

			tab_image[i].face = 1;
			tab_image[i].feat = feat;

			++i;
			nb_pos++;
		}
	}

	if (closedir(rep) == -1)
		exit(-1);

	rep = NULL;
	file = NULL;
	rep = opendir("./neg");

	if (rep == NULL) {
		printf("Fail reading neg folder");
		exit(1);
	}

	while((file = readdir(rep)) != NULL) {

		if(file->d_name[0] != '.' && file->d_name[1] != '.') {
			char src[256] = "./neg/";
			char *name = strcat(src, file->d_name);
			SDL_Surface *img = load_image(name);
			grey_scale(img);
			M = integral_img(img);
			
			struct HaarF *feat = malloc(sizeof(struct HaarF));
			HaarFeatures(M, feat);

			tab_image[i].face = 0;
			tab_image[i].feat = feat;

			nb_neg++;
			++i;
		}
	}

	if (closedir(rep) == -1)
		exit(-1);

	free(M); // free integral image

	//printf("ok");
	return tab_image;
}

int compute_weakclass(int threshold, int polarity, int features) {
	if(polarity)
		return (features < threshold)?1:0;
	else
		return (features > threshold)?1:0;
}

static int sp(struct ada_feat *feat_t, int threshold) {
	int sp = 0;
	for(int i = 0; feat_t[i].feat < threshold; i++) if(feat_t[i].face) sp++;
	return sp;
}

static int sm(struct ada_feat *feat_t, int threshold) {
	int sm = 0;
	for(int i = 0; feat_t[i].feat < threshold; i++) if(!feat_t[sm].face) sm++;
	return sm;
}

static int compute_threshold(struct ada_feat *feat_t) {
	quickSort(feat_t, 0, (nb_neg+nb_pos)-1);

	int threshold;
	int *error = malloc((nb_neg+nb_pos)*sizeof(int));

	for(int i = 0; i < nb_neg+nb_pos; ++i) {

		threshold = feat_t[i].feat;

		int error1 = sp(feat_t, threshold)+(nb_neg - sm(feat_t, threshold));
		int error2 = sm(feat_t, threshold)+(nb_pos - sp(feat_t, threshold));

		error[i] = (error1 < error2)?error1:error2;
	}

	int index = 0;
	int min_error = error[0];
	for(int i = 1; i < nb_neg+nb_pos; i++) {
		if(error[i] < min_error) {
			min_error = error[i];
			index = i;
		}
	}

	return feat_t[index].feat;
}

struct strongclass *adaboost(struct image *image_tab, unsigned int iter) {
	if(image_tab && (nb_neg+nb_pos) != 0) {
		float *weight = malloc((nb_pos+nb_neg)*sizeof(float));

		struct strongclass *strongclassifier = malloc(sizeof(struct strongclass));
		strongclassifier->wc = malloc(iter*sizeof(struct weakclass));
		strongclassifier->alpha = malloc(iter*sizeof(float));

		struct weakclass *temp_weak = malloc(nb_feat*sizeof(struct weakclass));

		struct ada_feat *feat_t = malloc((nb_pos+nb_neg)*sizeof(struct ada_feat));

		float *error = malloc(nb_feat*sizeof(float));

		int i = 0;
		for(; i < nb_pos; ++i) {
			weight[i] = 1/nb_pos;
		}
		for(; i < nb_pos + nb_neg; ++i) {
			weight[i] = 1/nb_neg;
		}

		for(unsigned int t = 0; t < iter; ++t) { //main ada loop

			float sum = 0;//normalize weights
			for(int j = 0; j < nb_pos + nb_neg; ++j) {
				sum += weight[j];
			}
			for(int j = 0; j < nb_pos + nb_neg; ++j) {
				weight[j] = weight[j]/sum;
			}

			for(i = 0; i < nb_feat; ++i) {
				for(int j = 0; j < nb_pos + nb_neg; ++j) {
					feat_t[j].face = image_tab[j].face;
					feat_t[j].feat = image_tab[j].feat[i].val;
				}
				//exit(0);
				int threshold = compute_threshold(feat_t);

				int spl = sp(feat_t, threshold);
				int smi = sm(feat_t, threshold);

				int polarity = (spl > smi)?1:0;

				temp_weak[i].feat->x = image_tab[0].feat[i].x;
				temp_weak[i].feat->y = image_tab[0].feat[i].y;
				temp_weak[i].feat->w = image_tab[0].feat[i].w; // scale_x
				temp_weak[i].feat->h = image_tab[0].feat[i].h; // swap h and w? initialement scale_y ici
				temp_weak[i].feat->type = image_tab[0].feat[i].type;
				temp_weak[i].t = threshold;
				temp_weak[i].p = polarity;

				error[i] = 0;
				for(int j = 0; j < nb_pos + nb_neg; ++j) { 
					error[i] += weight[j]*fabs((double) (compute_weakclass(threshold, polarity, image_tab[j].feat[i].val) - image_tab[j].face));
				}
			}

			float min_error = error[0];
			int index = 0;
			for(i = 1; i < nb_feat; ++i) {
				if(error[i] < min_error) {
					min_error = error[i]; 
					index = i;
				}
			}

			struct weakclass weakclassifier;
			weakclassifier.feat = temp_weak[index].feat;
			weakclassifier.t = temp_weak[index].t;
			weakclassifier.p = temp_weak[index].p;

			strongclassifier->wc[t] = weakclassifier;

			float beta = min_error/(1 - min_error);

			for(int j = 0; j < nb_pos + nb_neg; ++j) {
				weight[j] = weight[j]*pow(beta, 1-((compute_weakclass(weakclassifier.t, weakclassifier.p, image_tab[j].feat[index].val) == image_tab[j].face)?0:1));
			}

			strongclassifier->alpha[t] = log10(1/beta);
		}

		strongclassifier->nb = iter;

		free(feat_t);
		free(weight);
		free(temp_weak);
		free(error);

		return strongclassifier;
	}
	return NULL;
}
