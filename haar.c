# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

int*  Haar_feature_1 (int *MHaar, int **M, SDL_Surface *img){

	int scalex = 0, scaley = 0;

	while ( 2 + scalex < img->w - 1 && 1 + scaley <= img->h - 1){

		for (int j = 0; j < img->h - (1 + scaley) - 1; j++){
			for (int i = 0; i < img->w - (2 + scalex) - 1; i++ ){
				*MHaar = M[i][j]- M[i][1 + j + scaley]- 2 * M[1 + i + scalex][j] + 2 * M[1 + i + scalex][1 + j + scaley] + M[2 + i + scalex][j] - M[2 + i + scalex][2 + j + scaley];
				MHaar++;
			}
		}
		scalex += 2;
		scaley++;
	}

	return MHaar;

}

int* Haar_feature_2 (int *MHaar, int **M, SDL_Surface *img){
	int scalex = 0, scaley = 0;

	while ( 1 + scalex < img->w - 1 && 2 + scaley <= img->h - 1){

		for (int j = 0; j < img->h - (2 + scaley) - 1; j++){
			for (int i = 0; i < img->w - (1 + scalex) - 1; i++){ 
				*MHaar = M[i][j] + 2 * M[1+ i + scalex][1 + j + scaley] - 2 *  M[i][1 + j + scaley] - M[1 + i + scalex][j] - M[1 + i + scalex][2 + j + scaley] + M[2 + i + scalex][1 + j + scaley];
				MHaar++;
			}
		}
		scaley += 2;
		scalex++;
	}

	return MHaar;

}

/*  void Haar_feature_3 (int x, int y, int scale, int **M){
    }

    void Haar_feature_4 (int x, int y, int scale, int **M){
    }

    void Haar_feature_5 (int x, int y, int scale, int **M){
    }*/

int* haar(int **M, SDL_Surface *img)
{
	int *temp;
	int* M_Haar = malloc(sizeof(int) * 170000);
	temp = Haar_feature_1(M_Haar, M, img);
	temp = Haar_feature_2(temp, M, img);
	return M_Haar;

}
