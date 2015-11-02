# include <stdlib.h>
# include <stdio.h>
# include <SDL.h>
# include <SDL_image.h>

void adaboost(AdImage *imagesPos, AdImage *imagesNeg int M, int N){

int T = 136;
//int check = 0;
float weightSum;
float weightPos = 1 / (2 * M);
float weightNeg = 1 / (2 * N);

for(int i = 0; i < N; i++) imagesNeg[i].weight = weightNeg;
for(int i = 0; i < M; i++) imagesPos[i].weight = weightPos;

for(int t = 1; t < T; t++){
//if(check =! 0){
//1)
for(int i = 0; i < N; i++) weightSum += imagesNeg[i].weight;
for(int i = 0; i < M; i++) weightSum += imagesPos[i].weight;

for(int i = 0; i < N; i++) imagesNeg[i].weight = imagesNeg[i].weight/weightSum;
for(int i = 0; i < M; i++) imagesPos[i].weight = imagesPos[i].weight/weightSum;
//}

//2)

}
}
