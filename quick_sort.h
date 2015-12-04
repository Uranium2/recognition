#ifndef QUICKSORT_H
#define QUICKSORT_H
# include "adaboost.h"
# include "haar.h"

int part(struct HaarF *listH, int p, int r);

void quick_sort(struct HaarF *listH, int p, int r);

#endif
