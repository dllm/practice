#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int key;
        struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
        struct Node *temp = malloc (sizeof (struct Node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
}

// A function to find k'th largest element in a given tree.
void kthLargestUtil(struct Node *root, int k, int *c)
{
        // Base cases, the second condition is important to
        // avoid unnecessary recursive calls
        if (root == NULL || *c >= k)
                return;

        // Follow reverse inorder traversal so that the
        // largest element is visited first
        kthLargestUtil(root->right, k, c);

        // Increment count of visited nodes
        (*c)++;

        // If c becomes k now, then this is the k'th largest
        if (*c == k)
        {
                 printf ("K'th largest element is %d\n", root->key);

                return;
        }

        // Recur for left subtree
        kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void kthLargest(struct Node *root, int k)
{
        // Initialize count of nodes visited as 0
        int c = 0;

        // Note that c is passed by reference
        kthLargestUtil(root, k, &c);
}

/* A utility function to insert a new node with given key in BST */
struct Node* insert(struct Node* node, int key)
{
        /* If the tree is empty, return a new node */
        if (node == NULL) return newNode(key);

        /* Otherwise, recur down the tree */
        if (key < node->key)
                node->left  = insert(node->left, key);
        else if (key > node->key)
                node->right = insert(node->right, key);

        /* return the (unchanged) node pointer */
        return node;
}

// Driver Program to test above functions
int main()
{
        /* Let us create following BST
           50
           /     \
           30      70
           /  \    /  \
           20   40  60   80 */
        struct Node *root = NULL;
        root = insert(root, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);

        int c = 0;
        for (int k=1; k<=7; k++)
                kthLargest(root, k);

        return 0;
}
