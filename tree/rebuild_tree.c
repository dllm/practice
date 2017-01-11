/*
 *
 *
 *      http://www.geeksforgeeks.org/if-you-are-given-two-traversal-sequences-can-you-construct-the-binary-tree/
 *      http://articles.leetcode.com/construct-binary-tree-from-inorder-and-preorder-postorder-traversal
 *      http://edwardliwashu.blogspot.com/2013/01/construct-binary-tree-from-preorder-and.html
 *
 *
 *
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

test case 1:
20
113
435
1347
2405
2719
3093
4065
4135
4478
5086
5771
6260
6307
6728
7663
7904
8595
9278
9750
9898
20
4478
435
113
2405
1347
2719
4135
3093
4065
5086
9750
9278
8595
6307
5771
6260
7904
6728
7663
9898

4478 
435 5086 
113 2405 9750 
1347 2719 9278 9898 
4135 8595 
3093 6307 
4065 5771 7904 
6260 6728 
7663 



*/


#define MAX_Q_SIZE 500
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Tree {
        int val;
        struct Tree * left;
        struct Tree * right;
} Tree;


int element = 0;

/* frunction prototypes */
struct Tree** createQueue(int *, int *);
void enQueue(struct Tree **, int *, struct Tree *);
struct Tree *deQueue(struct Tree **, int *);

int Qsize ( void){
    
    return element;
}
 
/* Given a binary tree, print its nodes in level order
   using array for implementing queue */
void printLevelOrder(struct Tree* root)
{
    int rear, front;
    struct Tree **queue = createQueue(&front, &rear);
    struct Tree *temp_node = root;
    
    enQueue(queue, &rear, temp_node);
    int level;

    while (1) {
    
        level = Qsize();
        if (level == 0){
            break;
        }
        
        while (level > 0)
        {
                        
            temp_node = deQueue(queue, &front);
            printf("%d ", temp_node->val);
            /*Dequeue node and make it temp_node*/

           
            /*Enqueue left child */
            if (temp_node->left)
                enQueue(queue, &rear, temp_node->left);
 
            /*Enqueue right child */
            if (temp_node->right)
                enQueue(queue, &rear, temp_node->right);
 

            level --;
        
        }
        printf ("\n");
        
    }
}
 
/*UTILITY FUNCTIONS*/
struct Tree** createQueue(int *front, int *rear)
{
    struct Tree **queue =
        (struct Tree **)malloc(sizeof(struct Tree*)*MAX_Q_SIZE);
 
    *front = *rear = 0;
    return queue;
}
 

void enQueue(struct Tree **queue, int *rear, struct Tree *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
    element++;
}
 
struct Tree *deQueue(struct Tree **queue, int *front)
{
    (*front)++;
    element--;
    return queue[*front - 1];
    
}

 

Tree* do_constrctTree(int *pre, int preStart, int preEnd, int *in, int inStart, int inEnd);


/*
 * Complete the function below.
 */
Tree* do_constrctTree(int *pre, int preStart, int preEnd, int *in, int inStart, int inEnd){  
    
    if (inStart > inEnd) return NULL;  // need base case
    
    int root = pre[preStart];  
    int root_idx = 0;
    for (int i = inStart; i <= inEnd; i++ ){  //be careful
        
        if (in[i] == root){
            root_idx = i;
            
            break;
        }        
    }
    
    int len = root_idx - inStart;
    Tree * newTree  = malloc (sizeof (Tree));
    
    newTree->val = root;
    newTree->left = do_constrctTree(pre, preStart + 1, preStart + len, in, inStart, root_idx - 1);  //be carefull
    newTree->right = do_constrctTree(pre, preStart+len + 1, preEnd, in, root_idx + 1, inEnd);
    
    return newTree;
}

void constrctTree(int iInOrderArray_size, int* iInOrderArray, int iPreOrderArray_size, int* iPreOrderArray) {    
    Tree * NewTree;
    NewTree = do_constrctTree ( iPreOrderArray, 0, iPreOrderArray_size -1 , iInOrderArray, 0, iInOrderArray_size - 1  );
    
    printLevelOrder (NewTree);
    
}

int main() {
    
    int _iInOrderArray_size = 0;
    int _iInOrderArray_i;
    scanf("%d\n", &_iInOrderArray_size);
    int _iInOrderArray[_iInOrderArray_size];
    for(_iInOrderArray_i = 0; _iInOrderArray_i < _iInOrderArray_size; _iInOrderArray_i++) {
        int _iInOrderArray_item;
        scanf("%d", &_iInOrderArray_item);
        
        _iInOrderArray[_iInOrderArray_i] = _iInOrderArray_item;
    }
    
    
    int _iPreOrderArray_size = 0;
    int _iPreOrderArray_i;
    scanf("%d\n", &_iPreOrderArray_size);
    int _iPreOrderArray[_iPreOrderArray_size];
    for(_iPreOrderArray_i = 0; _iPreOrderArray_i < _iPreOrderArray_size; _iPreOrderArray_i++) {
        int _iPreOrderArray_item;
        scanf("%d", &_iPreOrderArray_item);
        
        _iPreOrderArray[_iPreOrderArray_i] = _iPreOrderArray_item;
    }
    
    constrctTree(_iInOrderArray_size, _iInOrderArray, _iPreOrderArray_size, _iPreOrderArray);
    
    return 0;
}


