#include <stdio.h>
#include <stdlib.h>

void rev (int *arr, int start, int end){

	while (start < end){
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}

}

void rotate (int *arr, int size, int k){

	int i = 0;
	int j = k;

	rev (arr, j, size-1);
	rev (arr, i, j-1);
	rev (arr, i, size -1 );

}

int main (void){
	int arr[] = {1,2,3,4,5,6,7,8};
	int k = 3;
	int size = sizeof (arr) / sizeof (int);

	rotate (arr,size, k);

	for (int i = 0; i< size; i++){
		printf ("%d ", arr[i]);
	}


}
