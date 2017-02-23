#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* random;
} Node;


Node* clone_LL (Node * head){

	Node * curr = head;

	while (curr){
		Node * newnode = malloc (list);
		Node * newnode->next = curr->next;
		newnode->data = curr->data;
		curr->next = newnode;
		curr = curr->next->next;
	}

	curr = head;

	while (curr){
		curr->next->random = curr->random->next;
		curr = curr->next->next;	
	}

	curr = head;
	
	Node * newhead = head->next;

	Node *copy_curr = head->next;


	while (curr){

		curr->next = copy_curr->next;
		copy_curr->next = copy_curr->next->next;
		curr = curr->next;
		copy_curr- = copy_curr->next
	}

	return newhead;

}

