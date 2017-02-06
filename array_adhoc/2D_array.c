#include <stdio.h>

#define ROW 4
#define COL 4

void search (int mat[ROW][COL], int n, int m, int target){

	int i = 0;
	int j = m-1;
	while (i<n && j >= 0){
		if (mat[i][j] == target) {
			printf ("found at %d %d\n", i, j);
			return ;
		}else {
			if ( target < mat[i][j] ){
				j--;
			}
			else {
				i++;
			}	

		}	

	}
	printf ("\nnot found\n");

}

int main()
{
	int mat[ROW][COL] = { {10, 20, 30, 40},
			  {15, 25, 35, 45},
			  {27, 29, 37, 48},
			  {32, 33, 39, 50},
	};
	int input;
	scanf ("%d", &input);
	search(mat, ROW, COL, input);

	return 0;
}



