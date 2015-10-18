# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include "pixel_operations.h"

void integral_img(SDL_Surface *img, int M[])
{
	int sum_int = 0;
	Uint8 sum = 0;
	for(int i = 0; i < img->w;i++){
		for(int j = 0; j < img->h;j++){
			SDL_GetRGB(getpixel(img,i,j), img->format, &sum, &sum, &sum);
			M[(i * img->w) + j] = sum;
			if(i == 0 && j == 0)
				sum_int = (int)sum;
			if(i == 0 && j != 0)
				sum_int = (int)sum + M[(i * img->w) + (j-1)];
			if(j == 0 && i != 0)
				sum_int = (int)sum + M[((i-1) * img->w) + j];
			if(i > 0 && j > 0)
				sum_int = (int)sum + M[((i-1) * img->w) + j] + M[(i * img->w) + (j-1)] - M[((i-1) * img->w) + (j-1)];
			M[(i * img->w) + j] = sum_int;

			printf("| %d ", M[i * img->w + j]);
		}
		printf("|\n");
	}
}

//Uint32 integral_img(SDL_Surface *img, unsigned x, unsigned y, unsigned width, unsigned height)
//{
//	return 0;
//}
