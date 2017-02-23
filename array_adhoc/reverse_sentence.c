#include <stdio.h>
#include <stdlib.h>




void rev_str (char *start, char* end){

	while (start < end){
		char tmp =*start;
		*(start++) = *end; //--
		*(end--) = tmp;
	}

}

void rev_word (char * str ){

	char *start = str;
	//char *end = str[strlen (str) - 1];
	char *curr = str;

	//rev_str ( start, end  );

	while ( *curr ) {
		curr++;
		if (*curr == ' '){
			rev_str (start, curr - 1);
			start = curr + 1;

		}
	/*	else if (*curr == '\n'){  // --
			rev_str (start, curr - 1);
		}*/
	}	
	rev_str (start, curr-1);

	rev_str (str, curr-1);
}



int main (){

	char str[] = {"this is a dog"};

	char *start = str;
	int size = sizeof (str) /sizeof (char); 
	
	
	rev_word (str);

	printf ("%s\n", start);

	return 0;
}
