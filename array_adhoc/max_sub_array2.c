#include <stdio.h>

int findmax (int *array, int size){

	int min_sum = 0;
	int sum = 0;
	int max_sum = 0;

	for (int i = 0; i < size; i++ ){

		sum += array[i];

		if (sum < min_sum){
			min_sum = sum;
		}

		if ( max_sum < sum - min_sum ){
			max_sum = sum - min_sum;
		}

	}

	return max_sum;
}


int main () {

	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

	printf ("%d\n", findmax (array, 7 ));	


	int array2[] = {904, 40, 523, 12, -335, -385, -124,481, -31};

	printf ("%d\n", findmax (array2, 9));	
}
