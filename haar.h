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

void haar1(HaarF *haar, int **M);
void haar2(HaarF *haar, int **M);
void haar3(HaarF *haar, int **M);
void haar4(HaarF *haar, int **M);
void haar5(HaarF *haar, int **M);

void HaarFeatures(int **M, HaarF *HaarList);
