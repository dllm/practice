#include <iostream>
#include <queue>
#include <deque>

using namespace std;



void sliding_windows_max (int A[], int N, int w){
	deque<int> D;

	int *B = new int[N]; 
	int i = 0;
	for (i = 0; i < w; i++){
		while (!D.empty() && A[i] >= D.back())
		       D.pop_back();	
		D.push_back(A[i]);
	}

	int j = 0;
	for (i = w, j = 0; i < N; i++, j++){
		B[j] = D.front();
		while (!D.empty() && A[i] >= D.back())
		       D.pop_back();
		while (!D.empty() && D.front() <= A[i])
			D.pop_front();	
		D.push_back(A[i]);
	}

	B[j++] = D.front();
	for (int k = 0; k< j; k++){

		cout << B[k] <<endl;
	}
}


int main (){

	int w = 3; //width of windows
	int A[] = { 1,3,-1,-3,5, 3, 6, 7 };

	sliding_windows_max (A, sizeof(A)/sizeof(A[0]),w);

}
