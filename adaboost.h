# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <dirent.h>
# include "integral_img.h"

#ifndef AdImage
#define AdImage

struct image {
	int face;
	struct HaarF *feat;
};

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

struct strongclass *adaboost(struct image *tab, unsigned int iter);

struct image *prepare_tab_image(int nb);
#endif
	
