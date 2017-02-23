void alternativeSplit(LinkedListNode* pList) {

	if (!pList) return;

	LinkedListNode * head1 = pList;

	if (!pList->next) {
		printf ("%d",pList->val);
		return;
	}

	LinkedListNode *head2 = pList->next;

	LinkedListNode *curr1 = head1;
	LinkedListNode *curr2 = head2;

	while ( curr1 && curr1->next ){
		curr1->next = curr2->next;
		if (curr2->next){
			curr2->next = curr2->next->next;
		}
		curr1 = curr1->next;
		curr2 = curr2->next;

	}

	while (head1) {
		printf ("%d", head1->val);
		head1 = head1->next;
		if (head1) printf (",");
	}
	printf ("\n");
	while (head2) {
		printf ("%d", head2->val);
		head2 = head2->next;
		if (head2) printf (",");
	}


}

