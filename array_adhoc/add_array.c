#include <stdio.h>
#include <stdlib.h>

int max (int a, int b){
	
	return ( a > b? a: b );

}

int *add_string (int *a1, int *a2, int size1, int size2, int *res_size){

	*res_size = max (size1, size2) + 1;

	int *res = malloc (sizeof(*res_size) * sizeof (int));

	int i = *res_size;
	int j, k;

	int carry = 0;

	int *large, *small;
	int small_size, large_size;

	if (size1 > size2){
		large = a1;
		small = a2;
		small_size = size2 - 1;
		large_size = size1 - 1;
	}
	else {
		small = a1;
		large = a2;
		small_size = size1 - 1;
		large_size = size2 - 1;
	}

	for (i = *res_size, j = small_size, k= large_size; j >= 0; i--, j--, k--){

		res[i] = large[k] + small[j] + carry;
	        if (res[i] >= 10) {
			carry = 1;
			res[i] -= 10;
		}else{
			carry = 0;
		}	
	}

	if (carry == 1){
		res[++i] = 1;
	}

	return res;
}


int main (void){

	int a1[]= {8,2,3};
	int a2[] = {9,7};
	int res_size = 0;

	int *res;

	int size1 = sizeof (a1)/sizeof (a1[0]);
	int size2 = sizeof (a2)/sizeof (a2[0]);

	res = add_string (a1, a2, size1, size2, &res_size);

	for (int i = 0; i < res_size; i++ ){
		printf ("%d ", res[i]);

	}

	return 0;
}
