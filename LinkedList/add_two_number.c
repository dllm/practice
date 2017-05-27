#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedListNode {
	int val;
	struct LinkedListNode *next;
} LinkedListNode;

int size_ll (LinkedListNode* pList){

	int cnt = 0;
	while (pList){
		pList = pList->next;
		cnt++;
	}
	return cnt;
}

LinkedListNode* even_odd(LinkedListNode* head1, LinkedListNode* head2){

	LinkedListNode* result_head = NULL;
	LinkedListNode* result_curr = NULL;
	LinkedListNode* tmp = NULL;

	LinkedListNode* curr1;
	LinkedListNode* curr2;

	int sum = 0;
	int carry = 0;

	curr1 = head1;
	curr2 = head2;

	while (curr1 || curr2){

		sum = 0;

		if (curr1){
			sum += curr1->val;
			curr1 = curr1->next;
		}	
		if (curr2){
			sum += curr2->val;
			curr2 = curr2->next;
		}	

		sum += carry;
		carry = sum/10;		
		sum = sum%10;
		if (result_head == NULL){
			result_head = malloc (sizeof (LinkedListNode));
			result_head->val = sum;
			result_curr = result_head;
		}
		else {
			tmp = malloc (sizeof (LinkedListNode));
			tmp->val = sum;
			result_curr->next = tmp;
			result_curr = tmp;
		}

	}//while

	if (carry){
		tmp = malloc (sizeof (LinkedListNode));
		tmp->val = carry;
		result_curr->next = tmp;
		result_curr = tmp;
	}

	result_curr->next = NULL;
	return result_head;
}

/* UTILITYd = even_odd (head);/ FUNCTIONS */
/* Function to push a LinkedListNode */
void push(struct LinkedListNode** head_ref, int new_val)
{
	/* allocate LinkedListNode */
	struct LinkedListNode* new_LinkedListNode =
		(struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));

	/* put in the val  */
	new_LinkedListNode->val  = new_val;

	/* link the old list off the new LinkedListNode */
	new_LinkedListNode->next = (*head_ref);

	/* move the head to point to the new LinkedListNode */
	(*head_ref)    = new_LinkedListNode;
}

/* Function to print linked list */
void printList(struct LinkedListNode  *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->val);
		node = node->next;
	}
}
/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct LinkedListNode* head1 = NULL;
	struct LinkedListNode* head2 = NULL;
	struct LinkedListNode* result_head = NULL;

	push(&head1, 4);
	push(&head1, 3);
	push(&head1, 2);
	push(&head1, 1);

	push(&head2, 9);
	push(&head2, 8);
	push(&head2, 7);
	push(&head2, 6);
	push(&head2, 5);

	printf("\nGiven linked list 1\n");
	printList(head1);

	printf("\nGiven linked list 2\n");
	printList(head2);


	result_head = even_odd (head1, head2);

	printf("\nresult linked list \n");
	printList(result_head);

	return(0);
}
