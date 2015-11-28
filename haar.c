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

void HaarFeatures(int **M, HaarF *HaarList)
{
	int featureSize[5][2] = {{2,1},{1,2},{3,1},{1,3},{2,2}};	
	int counter = 0, counter0 = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
	HaarF haar;
	/*haar.x = 0;
	  haar.y = 0;
	  haar.w = 23;
	  haar.h = 23;
	  haar = haar1(haar,M);*/
	for(int featType = 0; featType < 5; featType++){

		int w = featureSize[featType][0];
		int h = featureSize[featType][1];

		haar.x = 0;
		haar.y = 0;
		haar.w = w;
		haar.h = h;

		while (haar.y + haar.h < 24){
			while (haar.x + haar.w < 24){
				while (haar.y + haar.h < 24){
					while (haar.x + haar.w < 24){
						if (featType == 0){
							haar = haar1(haar,M);
							haar.type = 1;
							counter0++;
						}
						else if (featType == 1){
							haar = haar2(haar,M);
							haar.type = 2;
							counter1++;						
						}
						else if (featType == 2){
							haar = haar3(haar,M);
							haar.type = 3;
							counter2++;						
						}
						else if (featType == 3){
							haar = haar4(haar,M);
							haar.type = 4;
							counter3++;						
						}
						else if (featType == 4){
							haar = haar5(haar,M);
							haar.type = 5;
							counter4++;						
						}
						//printf("testx = %d, testy = %d \n",haar.w, haar.h);
						//printf("| %d ", haar.val);						
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
			haar.x = 0;
			haar.y += 1;
		}
	}
	//printf("|\n");
	//printf("%d \n", counter);
	printf(" Nb of features: %d \n Features 1: %d \n Features 2: %d \n Features 3: %d \n Features 4: %d \n Features 5: %d \n", counter, counter0, counter1, counter2, counter3, counter4);        
	//return HaarList;
}
