#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
 *  * Complete the function below.
 *   */
char* RLE(char* strinput) {

	int len = strlen(strinput);

	char *result = malloc (sizeof(char) * len);

	int i = 0;
	int j = 0;
	int cnt = 1;
	char count_str[1000];

	while (strinput[i] != '\0'){

		while (strinput[i] == strinput[i + 1] ){
			cnt++;
			i++;
		}

		if (cnt > 1){
			sprintf (count_str,"%d",cnt);
			for (int k = 0; count_str[k]; k++){
				result[j++]= count_str[k]; 
			}
		}


		result[j++] = strinput[i];

		cnt = 1;
		i++;
	}
	result[j] = '\0';
	return result;
}


int main () {

	char test_str1[] = "ABBBBCCCCCBBBDDDDDDDDDDDDDDD"; 

	char *result = RLE (test_str1);

	printf ("input %s\noutput %s\n", test_str1, result);


}

