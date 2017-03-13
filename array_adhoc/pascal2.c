#include <stdio.h>
#include <stdlib.h>

void printPascal(int n)
{
	int line = n;
	int i = 0;

	int **arr = (int **)malloc (sizeof (int *) * n );

	for (int j = 0; j < n; j++){
		arr[j] = malloc (sizeof (int) * n);
	}

	for (line = 0; line < n; line++){
	
		for (i = 0 ; i < line; i++){
			if (i== 0 || i == line-1) {
				arr[line][i] = 1;
				printf ("%d", arr[line][i]);
			}
			else {
				arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
				printf ("%d", arr[line][i]);
			}


		}	
		printf ("\n");
	}


}


int main (){
	printPascal(7);
}
