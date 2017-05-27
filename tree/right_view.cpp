#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp =  (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void right_view(struct node *root)
{

	queue<struct node *> S;

	if (root == NULL) return;

	S.push(root);

	int node_cnt = 0;

	while (1){

		node_cnt = S.size();

		if (S.size() == 0 ){
			break;
		}

		while (node_cnt > 0 ){

			if (node_cnt == 1)	
				cout<<S.front()->key<< " " ;
			root = S.front();
			S.pop();
			if (root->left !=NULL){
				S.push(root->left);
			}

			if (root->right != NULL){
				S.push(root->right);
			}
			node_cnt--;
		}

		cout << endl;
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
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
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	insert(root, 90);

	// print inoder traversal of the BST
	//level(root);
	//level_by_line(root);
	right_view (root);

	return 0;
}
