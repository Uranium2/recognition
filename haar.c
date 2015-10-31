# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

int*  Haar_feature_1 (int *MHaar, int **M, SDL_Surface *img){

	int scalex = 0, scaley = 0;

	while ( 2 + scalex < img->w - 1 && 1 + scaley < img->h - 1){

		for (int j = 0; j < img->h - (1 + scaley); j++){
			for (int i = 0; i < img->w - (2 + scalex); i++ ){
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

	while ( 1 + scalex < img->w - 1 && 2 + scaley < img->h - 1){

		for (int j = 0; j < img->h - (2 + scaley)-1; j++){
			for (int i = 0; i < img->w - (1 + scalex)-1; i++){ 
				*MHaar = M[i][j] + 2 * M[1+ i + scalex][1 + j + scaley] - 2 *  M[i][1 + j + scaley] - M[1 + i + scalex][j] - M[1 + i + scalex][2 + j + scaley] + M[2 + i + scalex][1 + j + scaley];
				MHaar++;
			}
		}
		scaley += 2;
		scalex++;
	}

	return MHaar;

}

int* Haar_feature_3 (int *MHaar, int **M, SDL_Surface *img){
	int scalex = 0, scaley = 0;

	while ( 3 + scalex < img->w -1 && 1 + scaley < img->h -1 ){
		for (int j = 0; j < img->h - (1 + scaley); j++){
			for (int i = 0; i < img->w - ( 3 + scalex); i++){
				*MHaar = M[i][j] + 2 * M[1 + i + scalex][1 + j + scaley] - M[i][1 + j + scaley] - 2 * M[1 + i + scalex][j] + 2 * M[2 + i + scalex][j] + M[3 + i + scalex][1 + j + scaley] 
					- 2 * M[2 + i + scalex][1 + j + scaley] - M[3 + i + scalex][j];
				MHaar++;
			}
		}
		scalex += 3;
		scaley ++;
	}
	return MHaar;   
}

int* Haar_feature_4 (int *MHaar, int **M, SDL_Surface *img){
	int scalex = 0, scaley = 0;

	while ( 1 + scalex < img->w -1 && 3 + scaley < img->h -1 ){
		for (int j = 0; j < img->h - (3 + scaley); j++){
			for (int i = 0; i < img->w - ( 1 + scalex); i++){
				*MHaar = -(M[i][j]) + M[1 + i + scalex][j] - 2 * M[1 + i + scalex][1 + j + scaley] + 2 * M[1 + i + scalex][2 + j + scaley] - M[1 + i + scalex][3 + j + scaley] 
					+ M[i][3 + j + scaley] - 2 * M[i][2 + j + scaley] + 2 * M[i][1 + j + scaley];
				MHaar++;
			}
		}
		scaley += 3;
		scalex ++;
	}
	return MHaar;

}

int* Haar_feature_5 (int *MHaar, int **M, SDL_Surface *img){
	int scalex = 0, scaley = 0;

	while ( 2 + scalex < img->w -1 && 2 + scaley < img->h -1 ){
		for (int j = 0; j < img->h - (2 + scaley); j++){
			for (int i = 0; i < img->w - ( 2 + scalex); i++){
				*MHaar = -(M[i][j]) + 2 * M[1 + i + scalex][j] - M[2 + i + scalex][j] + 2 * M[2 + i + scalex][1 + j + scaley] - M[2 + i + scalex][2 + j + scaley] 
									       + 2 * M[1 + i + scalex][2 + j + scaley] - M[i][2 + j + scaley] + 2 * M[i][1 + j + scaley] - 4 * M[1 + i + scalex][1 + j + scaley]; 
				MHaar++;
			}
		}
		scalex += 2;
		scaley += 2;
	}
	return MHaar;

}

int* haar(int **M, SDL_Surface *img)
{
	int *temp;
	int* M_Haar = malloc(sizeof(int) * 17000);
	temp = Haar_feature_1(M_Haar, M, img);
	temp = Haar_feature_2(temp, M, img);
	temp = Haar_feature_3(temp,M,img);
	temp = Haar_feature_4(temp,M,img);
	temp = Haar_feature_5(temp,M,img);
	return M_Haar;

}
