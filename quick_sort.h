#ifndef QUICKSORT_H
#define QUICKSORT_H

struct ada_feat {
	int feat;
	int face;
};

int part(struct ada_feat *M, int p, int r);

void quickSort(struct ada_feat *M, int p, int r);

#endif
