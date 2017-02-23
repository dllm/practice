#include <stdio.h>
#include <stdlib.h>


int find_min (int* array, int size ){

	int low = 0;
	int high = size - 1;
	int mid;

	while (low < high) {

		mid =  ((high + low) / 2);
		if (array[mid] < array[high] ){
			high = mid -1;
		}
		else {
			low = mid + 1;
		}
	}

	return low;

}


int main () {


	int arr[] = {5,6,7,8,9,10,1,2,3,4};
	int size = sizeof (arr) / sizeof (arr[0]);

	printf ("min index = %d\n", find_min (arr, size));

	int arr2[] = {1,2,3,4};
	int size2 = sizeof (arr2) / sizeof (arr2[0]);

	printf ("min index = %d\n", find_min (arr2, size2));
	
	int arr3[] = {2,1};
	int size3 = sizeof (arr3) / sizeof (arr3[0]);

	printf ("min index = %d\n", find_min (arr3, size3));
}

