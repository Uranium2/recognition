# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include <err.h>
//# include image treatment
# include "grey_scale.h"
# include "integral_img.h"

//# include else
# include "pixel_operations.h"
# include "haar.h"
# include "add.h"
# include "sdl_stuff.h"
# include "adaboost.h"
# include "quick_sort.h"
//

HaarF* List_Haar;
HaarF* begin;
int** M;

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 1;

	List_Haar = malloc(sizeof(HaarF)*160000);
	SDL_Surface *img;
	init_sdl();
	img = load_image(argv[1]);
	display_image(img);
	M = integral_img(img);
	wait_for_keypressed();
	begin = List_Haar;
	HaarFeatures(M, List_Haar);
	List_Haar = begin;
	for(int i = 0; i < 136656; i++)
		printf("| %d ", List_Haar[i].val);
	printf("| \n");
}
