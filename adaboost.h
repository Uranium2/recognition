# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

#ifndef AdImage
#define AdImage

typedef struct AdImage AdImage;
struct AdImage

{
	SDL_Surface *img;
        float weight;
        int val;
	

};

typedef struct WeakClassifier WC;
struct WeakClassifier

{
	double error;	
	double threshold;
	double parity;

}

typedef struct StrongClassifier SC;
struct StrongClassifier 

{
	double theta;
	int count;
	double alpha;
	
}
#endif
	
