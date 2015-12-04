# include <stdlib.h>
# include "quick_sort.h"

int part(struct image *img, int p, int r)
{
	int pivot = img[p].haar->val, i = p-1, j =r+1;
	struct image temp;
	while(1)
	{
		do j--; while(img[j].haar->val > pivot);
		do i++; while(img[i].haar->val < pivot);
		if(i < j)
		{
			temp = img[i];
			img[i] = img[j];
			img[j] = temp;
		}
		else
			return j;
	}
}

void quick_sort(struct image *img, int p, int r)
{
	int q;
	if(p < r)
	{
		q = part(img, p, r);
		quick_sort(img, p, q);
		quick_sort(img, q+1, r);
	}
}
