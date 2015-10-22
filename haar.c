# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

int Haar_feature_1 (int x, int y, int scale, int **M){
	return -M[x][y] + M[x][y+(23*scale)] + 2*M[x+(11*scale)][y] - 2*M[x+(11*scale)][y+(23*scale)] - M[x+(23*scale)][y] + M[x+(23*scale)][y+(23*scale)];
}

int Haar_feature_2 (int x, int y, int scale, int **M){
	return M[x][y]-M[x+(23*scale)][y]-2*M[x][y+(11*scale)]+2*M[x][y+(11*scale)]-2*M[x][y+(23*scale)]+M[x+(23*scale)][y+(23*scale)];
}

int Haar_feature_3 (int x, int y, int scale, int **M){
	return M[x][y]-2*M[x][y+(11*scale)]+M[x][y+(23*scale)]-2*M[x+(11*scale)][y]+4*M[x+(11*scale)][y+(11*scale)]-2*M[x+(11*scale)][y+(23*scale)]+M[x+(23*scale)][y+(23*scale)]-2*M[x+(23*scale)][y+(11*scale)]+M[x+(23*scale)][y];
}

int Haar_feature_4 (int x, int y, int scale, int **M){
	return -M[x][y]+M[x][y+(23*scale)]+2*M[x+(7*scale)][y]-2*M[x+(7*scale)][y+(23*scale)]-2*M[x+(15*scale)][y]+2*M[x+(15*scale)][y+(23*scale)]+M[x+(23*scale)][y]-M[x+(23*scale)][y+(23*scale)];
}

int Haar_feature_5 (int x, int y, int scale, int **M){
	return -M[x][y]+M[x+(23*scale)][y]+2*M[x][y+(7*scale)]-2*M[x+(23*scale)][y+(7*scale)]-2*M[x][y+(15*scale)]+2*M[x+(23*scale)][y+(15*scale)]+M[x][y+(23*scale)]-M[x+(23*scale)][y+(23*scale)];
}

int* haar(int **M, SDL_Surface *img)
{
	int* M_Haar = malloc(sizeof(int) * 170000);
	int x = 0;
	float scale = 1;
	while(scale * 24 <= img->w || scale * 24 <= img->h)
	{
		for(int i = 0; i < img->w ; i++)
		{
			for(int j = 0; j < img->h - (scale*24); j++)
			{
				M_Haar[x] = Haar_feature_1(i, j, scale, M);
				x++;
				M_Haar[x] = Haar_feature_2(i, j, scale, M);
				x++;
				M_Haar[x] = Haar_feature_3(i, j, scale, M);	
				x++;
				M_Haar[x] = Haar_feature_4(i, j, scale, M);
				x++;
				M_Haar[x] = Haar_feature_5(i, j, scale, M);
				x++;
				printf("x = %d i %d j %d scale %f \n",x, i,j, scale);
			}
		}
		scale = scale * 1.25 ;
	}
	return M_Haar;
}
