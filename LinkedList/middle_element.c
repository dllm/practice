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

void middle(LinkedListNode* head){

	LinkedListNode * fast = head;
	LinkedListNode * slow = head;

	while (fast && slow) {
		
		if (!fast->next || !slow->next ){
			break;
		}
		else {
			fast = fast->next->next;		
			slow = slow-> next;
		}
	}
	
	if (slow){
		printf ("\nmiddle is %d\n", slow->val);
	}

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

	middle (head);
        
	push(&head, 4);
	middle (head);
        push(&head, 11);
	middle (head);
        push(&head, 7);
        push(&head, 8);
        push(&head, 5);
        push(&head, 14);
        push(&head, 3);
        push(&head, 2);
        push(&head, 1);

        printf("\nGiven linked list \n");
        printList(head);

        middle (head);





        return(0);
}
