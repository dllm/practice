#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BUILD {
	int left;
	int height;
	int right;
};

struct BUILD building [] = {{1,11,5}, {2,6,7}, {3,13,9}, {12,7,16}, {14,3,25},
				{19,18,22}, {23,13,29}, {24,4,29}};

#define num_of_building 8 
#define MAX_RANGE 100

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
int main() {

	int min = 0xFFFF;
	int max = 0;

	/* scan min and max*/
	for (int i = 0; i < num_of_building; i++){
		min = MIN ( min, building[i].left);        
		max = MAX ( max, building[i].right);        
	}

	int output[MAX_RANGE];

	memset (output, 0, sizeof(output));

	int length = 0;

	int cur_x = 0;	
	for (int i = 0; i < num_of_building; i++){
		
		length = building[i].right - building[i].left;			
		cur_x = building[i].left;
		while (length >= 0){
		//printf ("height %d curx %d\n", building[i].height, cur_x);
			if (output[cur_x] < building[i].height){
				output[cur_x] = building[i].height;
			}
			
			cur_x++;
			length--;
		}

	}
	int previous_height = output[min];
	printf ("%d %d\n", min, output[min]);
	for (int k = min+1; k <=max+1; k++ ){
		if (output[k] > previous_height){
			printf ("%d %d\n", k, output[k]);
			previous_height = output[k];
		}
		else if (output[k] < previous_height){
			printf ("%d %d\n", k-1, output[k]);
			previous_height = output[k];
		}
	}


	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}

