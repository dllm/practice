#include <iostream>
#include <stack>


using namespace std;

void rev_stack (stack<int> S){

	if (S.empty()) return;

	int tmp = S.top();
	S.pop();
	rev_stack(S);

	S.push(tmp);
}



int main () {

	stack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);
	S.push(6);

	rev_stack (S);

	while (!S.empty()){
		cout << S.top() <<endl;
		S.pop();
	}
}
