/*
 *   http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
 *
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

129
131 244 179 239 73 # # 165 # # 184 147 219 200 # # 153 # # # 194 116 # # 130 17 166 # # 223 # # # 93 150 30 28 174 198 # # 169 232 155 # # 197 # # # 215 172 # # 26 # # 101 # # # 243 210 # # 112 204 202 # # 48 # # 138 14 # # 50 # # 16 106 160 # # 249 85 81 216 105 # # 65 # # # # 207 10 110 # # 18 # # # 212 152 12 75 69 206 # # 98 # # # 79 52 # # 128 # # 56 # # # 
56
85

result: 
16

127
45 225 78 237 # # 91 190 113 # # 197 # # # # 21 79 193 224 # # 173 35 54 204 # # 211 # # 207 137 16 186 # # 58 # # 37 # # # 103 246 84 # # 5 # # 136 247 112 # # 223 # # # 42 130 68 # # 147 171 # # 51 # # 104 9 27 # # 229 48 # # 135 # # 250 52 242 80 # # 151 # # # # 125 199 120 216 # # 59 # # 17 # # 7 164 # # 65 165 47 # # 82 # # 20 126 # # 191 # # 
242
52

result:

52

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


/*
 * Complete the function below.
 */

// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->val == n1 || root->val == n2)
        return root;
 
    // Look for keys in left and right subtrees
    struct Node *left_lca  = findLCA(root->left, n1, n2);
    struct Node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
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
    struct Node* root = createTree(_strArr_size, _strArr, &res_size);
    
    int _n1;
    scanf("%d", &_n1);
    
    int _n2;
    scanf("%d", &_n2);
    
    struct Node* res = findLCA(root, _n1, _n2);
    printf("%d\n", res->val);
    return 0;
}

