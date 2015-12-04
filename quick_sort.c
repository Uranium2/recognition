# include <stdlib.h>
# include "quick_sort.h"

int part(struct HaarF *listH, int p, int r)
{
	int pivot = listH[p].val, i = p-1, j =r+1;
	struct HaarF temp;
	while(1)
	{
		do j--; while(listH[j].val > pivot);
		do i++; while(listH[i].val < pivot);
		if(i < j)
		{
			temp = listH[i];
			listH[i] = listH[j];
			listH[j] = temp;
		}
		else
			return j;
	}
}

void quick_sort(struct HaarF *listH, int p, int r)
{
	int q;
	if(p < r)
	{
		q = part(listH, p, r);
		quick_sort(listH, p, q);
		quick_sort(listH, q+1, r);
	}
}
