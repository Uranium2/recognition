# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include "pixel_operations.h"

void integral_img(SDL_Surface *img)
{
	int** M;
	M = malloc(img->w * sizeof(int*));
	for (int i = 0; i < img->w; i++)
	{
		M[i] = malloc(img->h * sizeof(int));
	}
	int sum_int = 0;
	Uint8 sum = 0;
	for(int i = 0; i < img->h;i++){
		for(int j = 0; j < 274;j++){
			SDL_GetRGB(getpixel(img,i,j), img->format, &sum, &sum, &sum);

			if(i == 0 && j == 0)
				sum_int = (int)sum;
			if(i == 0 && j > 0)
				sum_int = (int)sum + M[i][j-1];
			if(j == 0 && i > 0)
				sum_int = (int)sum + M[i-1][j];
			if(i > 0 && j > 0)
				sum_int = (int)sum + M[i-1][j] + M[i][j-1] - M[i-1][j-1];
			M[i][j] = sum_int;

			printf("i=%d j=%d img%dx%d sum_int=%d\n ",i,j, img->h, img->w, sum_int);
		}
		printf("|\n");
	}
}

//Uint32 integral_img(SDL_Surface *img, unsigned x, unsigned y, unsigned width, unsigned height)
//{
//	return 0;
//}
