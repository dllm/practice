#include <iostream>
#include <queue>
#include <functional> 

using namespace std;

int array_i[] = {3,-1,2,6,4,5,8};

void sort_almost_array (int k, int arr[], int size ){

	priority_queue <int, vector<int>, greater<int> > min_heap;

	for (int i = 0; i < k ; i++){
		min_heap.push(arr[i]);
	}

	for (int i = k; i < size ; i++){

		if ( min_heap.top() < arr[i]){
			cout << min_heap.top()<< endl;
			min_heap.pop();
			min_heap.push(arr[i]);
		}
		else {
			cout << arr[i]<< endl;
		}
	}

	while (!min_heap.empty()){

		cout << min_heap.top() << endl;
		min_heap.pop();
	}

}

int main() {

	int k = 2;
	sort_almost_array (k, array_i, 7); 

}
