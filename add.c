#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <dirent.h>
#include <string.h>

void add(char* pathImg , char* pathBdd){
  
DIR* testBdd = NULL;
  testBdd = opendir(pathBdd);
  if(testBdd == NULL){
    printf("Wrong path for Data base \n");
    closedir(testBdd);
    return;
  }
  char* ext = strchr(pathImg,'.');
  if( strcmp(ext,"pgm")||strcmp(ext,"bmp")||strcmp(ext,"jpeg")||strcmp(ext,"jpg")||strcmp(ext,"png")){
    system("mv pathImg pathBdd");
    closedir(testBdd);
  }
  printf("Image's format isn't supported \n");
  closedir(testBdd);
  return;
}
      
