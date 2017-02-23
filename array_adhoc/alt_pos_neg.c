#include <stdio.h>
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	//int a[] = {2,3,-4,-9,-2,-7,1,-5,-6};
	int a[] = {-1,-2,-3,-4, 1,2,3,4};
	int j = 0;

	int size = sizeof (a)/sizeof(a[0]);

	int first, second, third;

	while (j+2 < size){

		first = second = third = 1;
		if (a[j] < 0) first = -1;
		if (a[j+1] < 0) second = -1;
		if (a[j+2] < 0) third = -1;

		if (first == second && second != third){
			int tmp;
			tmp = a[j+1];
			a[j+1] = a[j+2];
			a[j+2] = tmp;

		}
		j++;

	}

	for (int i = 0; i < size; i++){
		printf ("%d ", a[i]);
	}

	return 0;
}
