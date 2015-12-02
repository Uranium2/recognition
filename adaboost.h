# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <dirent.h>
# include "integral_img.h"

struct image{
	struct HaarF *haar; //  1 haar list = 1 image
	int weight;
	int pos; // 1 image is positive 0 is negative
};
double compute_tresh_min(struct image img);

double compute_tresh_max(struct image img);

void DSES(int nb_img, struct image image, double treshold, double teta, double      epsilon, double marge);

struct weakclass {
	struct HaarF *feat;
	int t; //threshold
	int p; // polarity
};

struct strongclass {
	struct weakclass *wc;
	float *alpha;
	int nb;
};	
