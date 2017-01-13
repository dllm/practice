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




bool isBSTfind (struct Node * node, int *min, int *max, int *res){
    
    int left_res = 0; int right_res = 0;
    int left_isBST = 0; int right_isBST = 0;
    
    if (node == NULL){
        return 1;
    }
    
    int left_n = 0, right_n = 0;
    int left_min = INT_MIN; int right_min = INT_MIN;
    int left_max = INT_MAX; int right_max = INT_MAX;
    
    bool leftIsBST = isBSTfind (node->left, &left_min, &left_max, &left_n);
    bool rightIsBST = isBSTfind (node->right, &right_min, &right_max, &right_n);  

    if (leftIsBST && rightIsBST) {
        
        if((!node->left || node->val >= left_max) && (!node->right || node->val <= right_max)){
            *res = left_n+ right_n + 1;
            *min = node->left ? left_min : node->val;
            *max = node->right ? right_max : node->val;
            return 1;
        }
    }    
        *res = left_n > right_n ? left_n :right_n;
        return 0;


}



int findLargestBST(struct Node* node) {
    
    int min = INT_MIN; int max = INT_MAX;
    int result = 0;
    
    int tmp = isBSTfind (node, &min, &min, &result );
    
    return result;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    int res;
    
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
    
    res = findLargestBST(n);
    fprintf(f, "%d\n", res);
    
    fclose(f);
    return 0;
}
