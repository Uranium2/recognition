# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include "pixel_operations.h"

Uint8 pixel_sum(SDL_Surface *img, int x, int y)
{
	Uint8 pixel_sum;
	if(x < img->w || y < img->h)
		return 0;
	else
	{
		pixel_sum = SDL_GetRGB(getpixel(img, x, y), img->format,
				&pixel_sum, &pixel_sum, &pixel_sum) + 
			pixel_sum(img, x - 1, y) +
			pixel_sum(img, x, y - 1) +
			pixel_sum(img, x - 1, y + 1);
		return pixel_sum;
	}
}

//Uint32 integral_img(SDL_Surface *img, unsigned x, unsigned y, unsigned width, unsigned height)
//{
//	return 0;
//}
