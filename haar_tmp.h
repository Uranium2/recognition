# include <stdlib.h>
# include <stdio.h>

typedef struct Haar_feature Haar;

struct Haar
{
        int feature; //nb au feature
        int value;
}

typedef struct Haar_feature_list Haar_list;

struct Haar_list
{
        Haar_feature data;
        Haar_list *next;
}

