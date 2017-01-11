#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*

   test case 1:

135
52 109 127 91 64 # # 28 57 53 221 222 189 28 # # 4 # # # # # # # 55 93 50 242 171 88 # # 38 # # # 202 5 155 # # 44 115 # # 95 # # # 190 # # 221 # # 221 166 # # 195 39 # # 45 # # 132 63 64 2 236 132 143 25 121 135 178 137 # # 194 # # # # # # # # # # 231 222 # # 183 146 18 186 160 # # 20 # # 169 # # # 71 145 39 # # 136 39 97 # # 69 # # # 159 140 217 # # 112 # # # 113 # # 


   result:
64 28 4 189 222 221 53 57 28 91 88 38 171 242 155 115 95 44 5 202 50 190 93 221 55 127 166 39 45 195 221 109 137 194 178 135 121 25 143 132 236 2 64 222 160 20 186 169 18 146 39 97 69 39 136 145 217 112 140 159 71 183 231 63 113 132 52 


   test case 2:
27
222 29 76 66 159 81 192 235 249 147 # # 14 # # # # 40 # # # # # 195 # # # 

   result:
147 14 249 235 192 40 81 159 66 76 195 29 222 





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

#define MAX_SIZE 100

// Stack type
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack =
            (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array =
           (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}
 
// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{  return stack->top == -1;  }
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// An iterative function to do post order traversal of a given binary tree
void postorderTraversal(struct Node* root)
{
    if (root == NULL) 
        return ;
 
    struct Node * save_root = root;
    // Create two stacks
    struct Stack* s1 = createStack(MAX_SIZE);
    struct Stack* s2 = createStack(MAX_SIZE);
 
    // push root to first stack
    push(s1, root);
    struct Node* node;
 
    // Run while first stack is not empty
    while (!isEmpty(s1))
    {
        // Pop an item from s1 and push it to s2
        node = pop(s1);
        push(s2, node);
 
        // Push left and right children of removed item to s1
        if (node->left)
            push(s1, node->left);
        if (node->right)
            push(s1, node->right);
    }
 
    // Print all elements of second stack
    while (!isEmpty(s2))
    {
        node = pop(s2);
        printf("%d ", node->val);
    }
    
    //return root;
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
    postorderTraversal(n);
    return 0;
}

