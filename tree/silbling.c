/*
http://articles.leetcode.com/first-on-site-technical-interview

*/

void connect(Node* p) {
	if (!p) return;
	if (p->leftChild)
		p->leftChild->nextRight = p->rightChild;
	if (p->rightChild)
		p->rightChild->nextRight = (p->nextRight) ?
			p->nextRight->leftChild :
			NULL;
	connect(p->leftChild);
	connect(p->rightChild);
}


