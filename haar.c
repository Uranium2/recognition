# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>
# include "haar.h"

HaarF haar1(HaarF haar, int **M){
	haar.val = M[haar.x][haar.y] - M[haar.x][haar.y + haar.h] 
		- 2 * M[haar.x + (haar.w)/2][haar.y] 
		+ 2 * M[haar.x + (haar.w)/2][haar.y + haar.h] 
		+ M[haar.x + haar.w][haar.y] 
		- M[haar.x + haar.w][haar.y + haar.h];
return haar;
}
HaarF haar2(HaarF haar, int **M){
	haar.val = M[haar.x][haar.y] - M[haar.x + haar.w][haar.y] 
		+ 2 * M[haar.x + haar.w][haar.y + (haar.h)/2] 
		- M[haar.x + haar.w][haar.y + haar.h] 
		+ M[haar.x][haar.y + haar.h] 
		- 2 * M[haar.x][haar.y + (haar.h)/2];
return haar;
}
HaarF haar3(HaarF haar, int **M){
	haar.val = M[haar.x][haar.y] - 2 * M[haar.x + (haar.w)/3][haar.y] 
		+ 2 * M[haar.x + ((haar.w)/3)*2][haar.y] 
		- M[haar.x + haar.w][haar.y] 
		+ M[haar.x + haar.w][haar.y + haar.h] 
		- 2 * M[haar.x + ((haar.w)/3)*2][haar.y + haar.h] 
		+ 2 * M[haar.x + (haar.w)/3][haar.y + haar.h] 
		- M[haar.x][haar.y + haar.h];
return haar;
}
HaarF haar4(HaarF haar, int **M){
	haar.val = -M[haar.x][haar.y] + M[haar.x + haar.w][haar.y]
		- 2 * M[haar.x + haar.w][haar.y + (haar.h)/3]
		+ 2 *  M[haar.x + haar.w][haar.y + ((haar.h)/3)*2]
		- M[haar.x + haar.w][haar.y + haar.h]
		+ M[haar.x][haar.y + haar.h]
		- 2 * M[haar.x][haar.y + ((haar.h)/3)*2]
		+ 2 * M[haar.x][haar.y + (haar.h)/3];
return haar;
}
HaarF haar5(HaarF haar, int **M){
	haar.val = -M[haar.x][haar.y] + 2 * M[haar.x + (haar.w)/2][haar.y]
		- M[haar.x + haar.w][haar.y]
		+ 2 * M[haar.x + haar.w][haar.y + (haar.h)/2]
		- M[haar.x + haar.w][haar.y + haar.h]
		+ 2 * M[haar.x + (haar.w)/2][haar.y + haar.h]
		- M[haar.x][haar.y + haar.h]
		+ 2 * M[haar.x][haar.y + (haar.h)/2]
		- 4 * M[haar.x + (haar.w)/2][haar.y + (haar.h)/2];
return haar;
}

HaarF* HaarFeatures(int **M, HaarF *HaarList)
{
	int featureSize[5][2] = {{2,1},{1,2},{3,1},{1,3},{2,2}};	
	int counter = 0;
	for(int featType = 0; featType < 5; featType++){

		HaarF haar;
		int w = featureSize[featType][0];
		int h = featureSize[featType][1];

		haar.x = 0;
		haar.y = 0;
		haar.w = w;
		haar.h = h;

		while (haar.y + haar.h <= 24 ){
			while (haar.x + haar.w <= 24){
				while (haar.y + haar.h <= 24){
					while (haar.x + haar.w <= 23){
						
						if (featType == 0){
							haar = haar1(haar,M);
						}
						else if (featType == 1){
							haar = haar2(haar,M);
						}
						else if (featType == 2){
							haar = haar3(haar,M);
						}
						else if (featType == 3){
							haar = haar4(haar,M);
						}
						else if (featType == 4){
							haar = haar5(haar,M);
						}
						//printf("testx = %d, testy = %d w = %d, h = %d \n",haar.x+haar.w, haar.y + haar.h, haar.w, haar.h);
printf(" | %d ", haar.val);						
*HaarList = haar;
						HaarList++;
						counter++;
						haar.w += w; 
					}
					haar.h += h;
					haar.w = w;
				}
				haar.h = h;
				haar.x += 1;
			}
			haar.x = 1;
			haar.y += 1;
		}
	}
printf(" | \n");
printf("%d \n", counter);        
return HaarList;
}
