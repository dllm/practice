/*
 *   
 *   How do you merge 2 Binary Search Trees in such a way that the resultant i
 *   tree contains all the elements of both the trees and also maintains the BST property.
 *   
 *   http://stackoverflow.com/questions/7540546/merging-2-binary-search-trees
 *
 *
 *
 * */


/*
 
 test case

 39
 4 # 80 50 18 6 5 # # 13 # # 32 28 23 22 # # 25 # # # 41 # # 66 53 52 # # 58 # # # 84 82 # # # 
 27
 69 18 12 # 16 # # 66 53 30 27 # # 37 # # 62 58 # # # # 95 73 # # # 

 expected output

 4 5 6 12 13 16 18 18 22 23 25 27 28 30 32 37 41 50 52 53 53 58 58 62 66 66 69 73 80 82 84 95 


 test case 2

 21
 75 63 50 9 # 37 # # # 64 # 66 # # 92 89 81 # # # # 
 23
 50 47 5 # 11 # 30 25 # # # # 89 79 62 # # 82 # # 91 # # 


 expected output

 5 9 11 25 30 37 47 50 50 62 63 64 66 75 79 81 82 89 89 91 92 
 
 
 
 
 
 
 */



#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};

struct Node* createTree(int strArr_size, char** arr, int* result_size) {
	if(*result_size == strArr_size) {
		return NULL;
	}
	if(*arr[*result_size] == '#') {
		*result_size += 1;
		return NULL;
	}

	struct Node *root = (struct Node*)malloc(sizeof(struct Node));
	int num = atoi(arr[*result_size]);
	*result_size += 1;
	root->val = num;
	root->left = createTree(strArr_size, arr, result_size);
	root->right = createTree(strArr_size, arr, result_size);

	return root;
}

void printInorder(struct Node* n) {
	if(!n) return;
	printInorder(n->left);
	printf("%d ", n->val);
	printInorder(n->right);
}

struct Node * do_balance (int *a, int start, int end){

	if (end < start) return NULL;

	int mid = (start + end) / 2;

	struct Node * New_Node = malloc (sizeof(struct Node));
	New_Node->val = a[mid];

	New_Node -> left = do_balance (a,start, mid -1 );
	New_Node -> right = do_balance (a, mid +1, end);

	return New_Node;

}

struct Node * balance (int *a, int len){

	return do_balance (a, 0,len - 1);

}



int index = 0;
void copy_tree_to_array ( struct Node * n, int * a ){

	if (n == NULL || a == NULL) return;


	copy_tree_to_array (n->left, a);

	a[index] = n->val;

	index++;

	copy_tree_to_array (n->right, a);


}



void merge_array (int *a, int size1, int *b, int size2){

	int k = size1 + size2 - 1;
	int i = size1 - 1;
	int j = size2 - 1;

	while (k >= 0){

		if (j < 0 || (i >= 0 && a[i] > b[j]) ){
			a[k] = a[i];
			k--; i--;
		}
		else {
			a[k] = b[j];
			k--;j--;            
		}                
	}    
}

/*
 *  * Complete the function below.
 *   */
struct Node* mergeTrees(struct Node* n1, struct Node* n2) {
	int a1[1000];
	int a2[1000];


	int num_node1, num_node2;


	index = 0;
	copy_tree_to_array (n1, a1 );

	num_node1 = index;

	index = 0;
	copy_tree_to_array (n2, a2 );

	num_node2 = index;

	merge_array (a1, num_node1, a2, num_node2 );


	return balance (a1, num_node1+num_node2);

}

int main() {


	int _str_size1 = 0;
	int _str_i;
	scanf("%d\n", &_str_size1);
	char* _str1[_str_size1];
	for(_str_i = 0; _str_i < _str_size1; _str_i++) {
		char* _str_item;
		_str_item = (char *)malloc(10240 * sizeof(char));
		scanf("%s",_str_item);

		_str1[_str_i] = _str_item;
	}
	int res_size = 0;
	struct Node* n1 = createTree(_str_size1, _str1, &res_size);

	int _str_size2 = 0;

	scanf("%d\n", &_str_size2);
	char* _str2[_str_size2];
	for(_str_i = 0; _str_i < _str_size2; _str_i++) {
		char* _str_item;
		_str_item = (char *)malloc(10240 * sizeof(char));
		scanf("%s",_str_item);

		_str2[_str_i] = _str_item;
	}
	int res_size2 = 0;
	struct Node* n2 = createTree(_str_size2, _str2, &res_size2);


	struct Node* res = mergeTrees(n1,n2);
	printInorder(res);

	return 0;
}
