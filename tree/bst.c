/*
 *Write a function isBST(BinaryTree *node) to verify if a given binary tree is a Binary Search Tree (BST) or not.
 *
 */

// http://articles.leetcode.com/determine-if-binary-tree-is-binary
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

/*
 *  * Complete the function below.
 *   */
bool isBST(struct Node* root) {
	static struct Node * previous = NULL;

	if (root == NULL) return 1;

	if (!isBST (root->left )) return 0;

	if (previous != NULL && root->val <= previous->val ) {        
		return 0;    
	}
	previous = root;

	if (!isBST (root -> right )) return 0;

	return 1;

}

int main() {

	int _str_size = 0;
	int _str_i;
	scanf("%d\n", &_str_size);
	char* _str[_str_size];
	for(_str_i = 0; _str_i < _str_size; _str_i++) {
		char* _str_item;
		_str_item = (char *)malloc(10240 * sizeof(char));
		scanf("%s",_str_item);

		_str[_str_i] = _str_item;
	}
	int res_size = 0;
	struct Node* n = createTree(_str_size, _str, &res_size);
	bool res = isBST(n);
	printf("%d\n", res);
	return 0;
}
