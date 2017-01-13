/*

hint: use post order!

http://stackoverflow.com/questions/9460255/reverse-a-binary-tree-left-to-right

So for example if we had the binary tree

     6
   /   \
  3     4
 / \   / \
7   3 8   1
Reversing it would create

     6
   /   \
  4     3
 / \   / \
1   8 3   7

*/

/*
 * Complete the function below.
 */
struct Node* flipTree(struct Node* node) {

    struct Node * temp;
    
    if (node == NULL) return NULL;
    
    node->left= flipTree (node->left);
    node->right= flipTree (node->right);
    
    
    temp = node->left;
    node->left = node->right;
    node->right = temp;

    return node;
}

