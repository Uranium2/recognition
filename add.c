#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <dirent.h>

int add(char* pathImg , char* pathBdd){
  DIR* testBdd = NULL;
  testBdd = opendir(pathBdd);
  if(testBdd == NULL){
    printf("Wrong path for Data base");
    return 1;
  }
  char* ext = strchr(pathImg,'.');
  if( strcmp(ext,"pgm")||strcmp(ext,"bmp")||strcmp(ext,"jpeg")||strcmp(ext,"jpg")||strcmp(ext,"png")){
    system("mv pathImg pathBdd");
    return 0;
  }
  printf("Image's format isn't supported");
  return 1;
}
      
