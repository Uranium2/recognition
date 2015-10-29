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
	float scale = 1;
	int x = 0;

	for(float size_box = 24; size_box <= img->h || size_box <= img->w; size_box = size_box * 1.25) // size of box
	{
		for(int xb = 0; xb + size_box <= img->w; xb++) // Moving box X
		{
			for(int yb = 0; yb + size_box <= img->h; yb++) // Moving box Y
			{
				for(float size_haar = 24; size_haar <= size_box; size_haar = size_haar * 1.25 ) // size of haar feature (smallest 24*24)
				{
					for(int xh = 0; xh + size_haar <= size_box; xh++) // Moving Haar 1,2,3,4,5 in X in the box
					{
						for(int yh = 0; yh + size_haar <= size_box; yh++) // Moving Haar 1,2,3,4,5 in Y in the box
						{
							printf("size_box=%f xb=%d yb=%d size_haar=%f xh=%d yh=%d scale=%f x=%d\n",size_box, xb, yb, size_haar, xh, yh, scale, x);
							M_Haar[x] = Haar_feature_1(xh, yh, 1, M);
							x++;
							M_Haar[x] = Haar_feature_2(xh, yh, 1, M);
							x++;
							M_Haar[x] = Haar_feature_3(xh, yh, 1, M);
							x++;
							M_Haar[x] = Haar_feature_4(xh, yh, 1, M);
							x++;
							M_Haar[x] = Haar_feature_5(xh, yh, 1, M);
							x++;
						}
					}
					scale = scale * 1.25;
				}
			}
		}
	}
	return M_Haar;
}
