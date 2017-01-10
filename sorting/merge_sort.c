#include <stdio.h>
#include <stdlib.h>

void merging (int *a, int start, int end, int mid,int size){

	//int *b = malloc (size * sizeof (int) * 2) ;
	int *b = malloc (size * sizeof (int) ) ;
	
	int left = start;
	int right = mid + 1;

	int curr = start; /* b pointer */

	for (; left <= mid && right <= end; curr++){
		if (a[left] <= a[right] ) {
			b[curr] = a[left];
			left++;
		}
		else {
			b[curr] = a[right];
			right++;
		}

	}

	while (left <= mid){
		b[curr++] = a[left++];
	}

	while (right <= end){
		b[curr++] = a[right++];
	}

	for (int i = start; i <= end; i++){
		a[i] = b[i];
	}

	free (b);
}


void merge_sort (int *a , int start, int end , int size){

	if (start >= end ) return;
	int mid = (start + end) / 2;

	merge_sort(a, start, mid , size);
	merge_sort (a, mid + 1, end, size );

	merging(a, start, end, mid, size );
}



int main (void){

	int a[] = { 3,4,5,6,7,4,1,0,9,8};
	int size = sizeof (a) /sizeof (a[0]);
	merge_sort (a, 0, size -1 ,size);

	for (int i = 0; i < size; i++) {
		printf ("%d ", a[i]);
	}	
	return 0;
}
