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

LinkedListNode* rem_x(LinkedListNode* list, int x){

	LinkedListNode * head = list;
	LinkedListNode * curr = list->next;
	LinkedListNode * prev = list;

#if 1 
	if (!list) {
		return list;
	}

	if (!list->next){
		if (list->val > x){
			free(list);
			return NULL;	
		}
		return list;
	}
#endif
	while (curr){

		if (curr->val > x){
			printf ("\nremove %d", curr->val);
			prev->next = curr->next;
			curr = curr->next;
			free(curr);


		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	return head;
}

/* UTILITY FUNCTIONS */
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
	struct LinkedListNode* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 4);
#if 0 
	push(&head, 11);
	push(&head, 7);
	push(&head, 8);
	push(&head, 5);
	push(&head, 14);
	push(&head, 3);
	push(&head, -2);
	push(&head, 1);
#endif
	printf("\nGiven linked list \n");
	printList(head);

	head = rem_x (head, 3);

	printf("\nsort Linked list \n");
	printList(head);

	return(0);
}
