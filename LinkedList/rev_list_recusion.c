#include <iostream>

using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next;
    Node (int x) {
	data = x;
    }
};
 
// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data 
             << endl;
        ptr = ptr->next;
    }
}
 
// This function clones a given linked list
// in O(1) space
Node* rev(Node *start)
{
	if (!start) return start; 

	if (!start->next) return start; 
	
	Node * newhead = rev (start->next);

	start->next->next = start;
	start->next = NULL;

	return newhead;

}

 
// Driver code
int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
 
 
    cout << "Original list : \n";
    print(start);
 
    cout << "\nCloned list : \n";
    Node *prev = NULL;
    Node *cloned_list = rev(start);
    if (!cloned_list) {
	cout << "NULL\n" << endl;
	return 1 ;
    }
    print(cloned_list);
 
    return 0;
}
