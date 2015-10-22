# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

int Haar_feature_1 (int x, int y, int scale, int **M);
int Haar_feature_2 (int x, int y, int scale, int **M);
int Haar_feature_3 (int x, int y, int scale, int **M);
int Haar_feature_4 (int x, int y, int scale, int **M);
int Haar_feature_5 (int x, int y, int scale, int **M);

int* haar(int **M, SDL_Surface *img);
