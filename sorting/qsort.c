#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int gSize = 0;

void print_array (int *a){

	printf ("\n");
	for (int i = 0; i < gSize; i++){
		printf ("%d ",a[i]);
	}

	printf ("\n");
}

void swap (int *a, int x, int y){
	int tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;	

}

int do_partition_first_element(int *a, int start, int end){

	int pivot = a[start];
	int left = start;
	int right = end ;

	while (left < right){

		while (a[left] <= pivot){
			left++;
		}

		while (a[right] >= pivot){
			right--;
		}
		
		if (left < right ){
			swap (a, right, left);
	//		printf ("\n swap: right %d light %d", right, left);
		}
	}
	swap (a, start, right);

	return right;
}


int do_partition_last_element(int *a, int start, int end){

	int pivot = a[end];
	int left = start;
	int right = end  - 1 ;

	while (left < right){

		while (a[left] <= pivot && left < end){
//			printf ("\n left[%d]= %d\n", left, a[left]);
			left++;
		}

		while (a[right] >= pivot && right >= start){
//			printf ("\n right[%d]= %d\n", right,a[right]);
			right--;
		}
		
		if (left < right ){
			swap (a, right, left);
//			printf ("\n swap right %d left %d\n", a[right], a[left]);
//			print_array(a);
		}
	}
	swap (a, left, end);
//	printf ("\nexit, swap Left pos %d, end pos %d ", left, end);
	return left;
}

void Qsort(int *  a, int start, int end)  {

	int index;

	if (start >= end ) return;

	//index = do_partition_first_element (a, start, end );	
	index = do_partition_last_element (a, start, end );	

	//Qsort ( a, index + 1, end);
	Qsort ( a, start, index -1);
	Qsort ( a, index + 1, end);

}
int main(void) {

	int a[] = {7,10,11,5,2,3,4,6,9,1};
	int size = sizeof (a) /sizeof(int);
	printf ("size %d\n", size);
	gSize = size;
	Qsort( a , 0, size - 1); 
	for (int i = 0; i < size; i++){

		printf ("%d ", a[i]);
	}

	printf ("\n ");
	return 0;
}

