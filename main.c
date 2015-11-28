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

int main()
{
	struct image *i = prepare_tab_image(2);
	if(i[0].feat) {
		struct strongclass *strong = adaboost(i, 2);

		for(int j = 0; j < 2; ++j) {
			printf("%d ", strong->wc[j].feat->type);
			printf("%d ", strong->wc[j].feat->x);
			printf("%d ", strong->wc[j].feat->y);
			printf("%d ", strong->wc[j].feat->w);
			printf("%d\n", strong->wc[j].feat->h);
		}
	}
	
}
