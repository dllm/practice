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

LinkedListNode* even_odd(LinkedListNode* head){

	LinkedListNode * odd_head = NULL;
	LinkedListNode * even_head = NULL;
	LinkedListNode * odd_tail = NULL;
	LinkedListNode * even_tail = NULL;
	LinkedListNode * curr = head;


	while ( curr ) {
	
		if (curr->val & 1 ){
			if (!odd_head){
				odd_head = curr;
				odd_tail = curr;
			}
			else {
				odd_tail->next =  curr;
				odd_tail = odd_tail->next;
			}
			curr = curr->next;
		}else{
			if (!even_head){
				even_head = curr;
				even_tail = curr;
			}
			else {
				even_tail->next =  curr;
				even_tail = even_tail->next;
			}
			curr = curr->next;
		}
	}
	if (odd_head != NULL){
		odd_tail->next = even_head;
	}
	else {
		odd_head = even_head;
	}
	return odd_head;
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
        struct LinkedListNode* head = NULL;

        push(&head, 4);
        push(&head, 11);
        push(&head, 7);
        push(&head, 8);
        push(&head, 5);
        push(&head, 14);
        push(&head, 3);
        push(&head, 2);
        push(&head, 1);

        printf("\nGiven linked list \n");
        printList(head);

        head = even_odd (head);

        printf("\nresult linked list \n");
        printList(head);

        return(0);
}
