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

LinkedListNode* merge(LinkedListNode* l1, LinkedListNode* l2){

        LinkedListNode* left = l1;
        LinkedListNode* right = l2;

        LinkedListNode* newHead = NULL;
        LinkedListNode* prev = NULL;


        if ( ((l1 && l2) && (l1->val < l2 ->val )) || (l1 && !l2)){
                newHead = l1;
                left = left->next;
        }
        else if (((l1 && l2) && (l2->val < l1->val )) || (l2 && !l1)){
                newHead = l2;
                right = right->next;
        }

        prev = newHead;

        while ( left && right ){

                if (left->val < right->val){
                        prev->next = left;
                        prev = left;
                        left = left -> next;

                }
                else {
                        prev->next = right;
                        prev = right;
                        right = right->next;

                }
        }

        while (left) {

                prev->next = left;
                prev = left;
                left = left->next;
        }

        while (right){
                prev->next = right;
                prev = right;
                right = right->next;
        }
        return newHead;
}

LinkedListNode* rec_ms(LinkedListNode* head, int len) {

        if (len == 0 || len == 1 ) return head;

        int halflen = len / 2;

        LinkedListNode *tail = head;
        LinkedListNode *prev = head;

        for (int i = 0; i < halflen && tail; i++){

                prev = tail;
                tail = tail->next;
        }
        prev->next = NULL;

        LinkedListNode* l1 = rec_ms( head, halflen);

        LinkedListNode* l2 = rec_ms( tail, len-halflen);

        return merge (l1, l2);

}

LinkedListNode* mergeSortList(LinkedListNode* pList) {

        return rec_ms (pList, size_ll(pList));

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
        push(&head, -1);
        push(&head, 11);
        push(&head, 7);
        push(&head, 8);
        push(&head, 5);
        push(&head, 14);
        push(&head, 3);
        push(&head, -2);
        push(&head, 1);

        printf("\nGiven linked list \n");
        printList(head);

        head = mergeSortList (head);

        printf("\nsort Linked list \n");
        printList(head);

        return(0);
}
