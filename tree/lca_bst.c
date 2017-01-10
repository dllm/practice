#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
} ;


// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = malloc ( sizeof (struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
/*
struct Node * lca(struct Node * root, int v1,int v2)
{
	if (root == NULL ) return NULL;

	if (root->data == v1 || root->data == v2) return root;

	struct Node * left = lca (root->left, v1, v2);
	struct Node * right = lca (root->right, v1, v2);
	
	if (left && right) return root;

	if (left != NULL){
		return left;
	}
	else{
		return right;
	}
}
*/
struct Node * lca(struct Node * root, int v1,int v2)
{

	if (root == NULL) return NULL;

	if (root->data > v1 && root->data > v2)
		return lca(root->left, v1, v2);

	if (root->data < v1 && root->data < v2)
		return lca(root->right, v1, v2);

	return root;


}
/* A utility function to insert a new node with given data in BST */
struct Node* insert(struct Node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(data);

	/* Otherwise, recur down the tree */
	if (data < node->data)
		node->left  = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

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

	//int c = 0;
	//for (int k=1; k<=7; k++)
	//	kthLargest(root, k);
	struct Node * tmp = lca (root, 50, 70);

	if (tmp) {
		printf ("%d \n", tmp->data);
	}else {
		printf ("NULL\n");
	}
	return 0;
}
