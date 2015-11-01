# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

#ifndef HAAR
#define HAAR

typedef struct HaarF HaarF;
struct HaarF

{

	int x;
	int y;
	int w;
	int h;
	int val;

};

#endif

HaarF haar1(HaarF haar, int **M);
HaarF haar2(HaarF haar, int **M);
HaarF haar3(HaarF haar, int **M);
HaarF haar4(HaarF haar, int **M);
HaarF haar5(HaarF haar, int **M);

void HaarFeatures(int **M, HaarF *HaarList);
