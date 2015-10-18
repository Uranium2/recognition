# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include "pixel_operations.h"

SDL_Surface* integral_img(SDL_Surface *img)
{
	Uint8 sum = 0;
	Uint8 temp0 = 0;
	Uint8 temp1 = 0;
	Uint8 temp2 = 0;
	for(int i = 0; i < img->w;i++){
		for(int j = 0; j < img->h;j++){
			SDL_GetRGB(getpixel(img,i,j), img->format, &sum, &sum, &sum);
			SDL_GetRGB(getpixel(img,i-1,j), img->format, &temp0, &temp0, &temp0);
			SDL_GetRGB(getpixel(img,i,j-1), img->format, &temp1, &temp1, &temp1);
			SDL_GetRGB(getpixel(img,i-1,j-1), img->format, &temp2, &temp2, &temp2);
			sum = sum + temp0 + temp1 - temp2;
			putpixel(img,i,j,SDL_MapRGB(img->format, sum, sum, sum));
		}

	}
	return img;
}

//Uint32 integral_img(SDL_Surface *img, unsigned x, unsigned y, unsigned width, unsigned height)
//{
//	return 0;
//}
