#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome (char * str) {

	int i = 0;
	int j = strlen (str) - 1;

	if (!str) return 0;

	while (i != j){
		
		if (str[i++] != str[j--])
		       	return 0;
	}
	return 1;
}

int is_rotate_palindrome (char * str, int size ){

	char * r_str = malloc (sizeof (char) * size );

	for (int i = 0; i < size; i++ ){
		str [size] = str [0];
		
		for (int j = 0; j < size; j++ ) {
			str[j] = str[j+1];
		}
		str[size] = '\0';

		if (is_palindrome (str )) {
			free (r_str);
			return 1;	
		}	

	}
	free (r_str);	
	return 0;

}

int main() {

	char str1[3] = "aab";

	if (is_rotate_palindrome (str1, strlen(str1))){
		printf ("YES\n");
	}
	else {
		printf ("NO\n");
	}
	
	char str2[4] = "abcd";

	if (is_rotate_palindrome (str2, strlen(str2))){

		printf ("YES\n");
	}
	else {
		printf ("NO\n");
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
