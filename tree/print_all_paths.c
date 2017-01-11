/*
 *
 *
 *   http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
 *
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*

	test case 1: 
47
89 110 93 162 83 100 # # 204 # # 69 199 # # 181 # # # 184 161 143 6 # # 13 # # # # 62 150 # # 168 114 247 # # 186 85 # # 204 # # # 
141
18 46 73 21 77 248 # # 196 # # # 134 # # 182 83 180 # # 71 22 # # 16 57 40 # # 177 # # # # 75 166 61 56 146 123 # # 17 # # # # # 72 80 172 105 104 # # 84 # # # 3 176 98 62 # # 227 18 # # 96 # # # # 183 206 # # 44 146 211 200 55 100 85 # # 6 # # # # 61 247 128 37 177 118 125 229 # # 249 # # # # # # # 173 230 80 88 # # 122 # # # # 208 144 126 1 249 58 # # 82 # # # # 122 # # # 248 # # 

	output: 
89 110 93 162 83 100 
89 110 93 162 83 204 
89 110 93 162 69 199 
89 110 93 162 69 181 
89 110 184 161 143 6 
89 110 184 161 143 13 
89 62 150 
89 62 168 114 247 
89 62 168 114 186 85 
89 62 168 114 186 204 



*/


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


int arr[1000];

/*
 * Complete the function below.
 */
void printAllPaths(struct Node *root) {

    printall (root, 0);
}


void printall (struct Node * root, int cur_hgt){
    
     if (root == NULL ) {
        return;       
    }
    
    arr[cur_hgt] = root->val;
    cur_hgt++;
    if (root->left == NULL && root->right == NULL){
        print_line (cur_hgt);
        
    }
           
    printall (root->left, cur_hgt);
    printall (root->right, cur_hgt);   
  
}

void print_line (int cur_hgt){
    
    for (int i = 0; i < cur_hgt; i++){
        
        printf ("%d ", arr[i]);
    }

    printf ("\n");
}

int main() {
   
        int _strArr_size = 0;
    int _strArr_i;
    scanf("%d\n", &_strArr_size);

    char* _strArr[_strArr_size];
    for(_strArr_i = 0; _strArr_i < _strArr_size; _strArr_i++) {
        char* _strArr_item;
        _strArr_item = (char *)malloc(10240 * sizeof(char));

        scanf("%s",_strArr_item);
        _strArr[_strArr_i] = _strArr_item;
    }

    int res_size = 0;
    struct Node* n = createTree(_strArr_size, _strArr, &res_size);
    printAllPaths(n);
    
    return 0;
}

