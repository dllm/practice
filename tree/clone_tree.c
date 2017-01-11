#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*

test case:
47
89 110 93 162 83 100 # # 204 # # 69 199 # # 181 # # # 184 161 143 6 # # 13 # # # # 62 150 # # 168 114 247 # # 186 85 # # 204 # # # 

result:
100 83 204 162 199 69 181 93 110 6 143 13 161 184 89 150 62 247 114 85 186 204 168


test case:
185
27 178 133 175 187 33 108 7 190 # # 179 # # # 95 42 230 # # 231 # # # 24 2 58 # # 27 216 # # 115 153 60 112 # # 169 # # # 180 128 100 # # 165 # # # 131 52 233 1 144 # # 5 94 114 125 73 152 # # 179 # # # # # # # # 111 # # 232 # # 27 182 100 # # 49 # # 102 142 186 195 219 43 # # 114 # # # # 34 49 89 # # 188 # # 246 75 138 62 # # 1 44 153 160 209 # # 56 # # # # 34 # # 13 228 # # 217 149 78 185 123 96 119 # # 134 # # # # # # # # 175 90 65 65 136 # # 198 # # 125 # # # # 7 213 119 60 177 102 # # 232 # # # # # # # 

result:
190 7 179 108 33 230 42 231 95 187 58 2 216 27 112 60 169 153 115 100 128 165 180 24 144 1 152 73 179 125 114 94 5 233 52 131 111 175 232 133 100 182 49 27 43 219 114 195 186 142 89 49 188 34 62 138 209 160 56 153 44 1 34 75 228 13 119 96 134 123 185 78 149 217 246 102 136 65 198 65 125 90 175 178 102 177 232 60 119 213 7 27 






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


/*
 * Complete the function below.
 */
struct Node* cloneTree(struct Node* node) {
        
    struct Node* new_node = NULL;
            
    if (node){
        new_node = malloc(sizeof (struct Node));
        new_node->val = node -> val;
        new_node->left = cloneTree (node -> left);
        new_node->right = cloneTree (node -> right);
    }
    return new_node;
    
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

    struct Node* clone = cloneTree(n);
    printInorder(clone);
    return 0;
}


