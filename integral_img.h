// integral_img.h

# include <stdlib.h>
# include <SDL.h>

Uint32 pixel_sum(SDL_Surface *img, int x, int y);

Uint32 integral_img(SDL_Surface *img, unsigned x, unsigned y, unsigned width, unsigned height);
