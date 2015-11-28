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
//

int main(int argc, char *argv[])
{
	if(argc != 2)
		return 1;
	struct image *i = prepare_tab_image(2);
	if(i[0].feat) {
		struct strongclass *strong = adaboost(i, 2);

		for(int j = 0; j < 2; ++j) {
			printf("%d ", strong->wc[j].f.type);
			printf("%zu ", strong->wc[j].f.x);
			printf("%zu ", strong->wc[j].f.y);
			printf("%zu ", strong->wc[j].f.scale_x);
			printf("%zu\n", strong->wc[j].f.scale_y);
		}
	}
	
}
