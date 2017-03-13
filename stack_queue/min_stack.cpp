#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

stack<int> S;
stack<int> Aux_S;

int min_stack (){
	
	if (Aux_S.empty()) 
		return 0xFFFF;
	else
		return Aux_S.top();

}


void push ( int element ){
	
	S.push (element);

	if (Aux_S.empty()) {
		Aux_S.push(element);
		return;

	}
	if (element <= Aux_S.top()){
		Aux_S.push(element);
	}
}

void pop ( void ){

	if (S.empty()) {
		cout << "empty\n" <<endl;
		return;
	}	
	if ( !Aux_S.empty() && S.top() == Aux_S.top()){
		Aux_S.pop();
	}

	S.pop ();
}


int main () {

	push (9);
	cout << "min="<< min_stack() << endl;
	push (-3);
	cout << "min="<< min_stack() << endl;
	pop();
	cout << "min="<< min_stack() << endl;
}


