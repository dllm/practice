#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

stack<int> S1;
stack<int> S2;


void push ( int element ){
	S1.push(element);	
}

int pop ( void ){
	
	if (S2.empty()){
		while (!S1.empty()){
			S2.push(S1.top());
			S1.pop();
		}
	}

	if (S2.empty()){
		cout << "empty" <<endl;
		return -1;
	}

	int result = S2.top();
	S2.pop();
	return result;
}


int main () {

	push (9);
	push (3);
	cout << pop() << endl;
	push (2);
	push (1);
	push (3);
	push (1);
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;

	
	
}


