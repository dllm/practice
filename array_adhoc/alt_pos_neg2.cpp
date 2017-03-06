#include <iostream>

using namespace std;

void swap (int *a, int i, int j){
	int tmp;

	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;

}

void rearrange (int *arr, int n){

	int i = 0; int j = n;

	while (i < j){
		while (arr[i] < 0) i++;
		while (arr[j] > 0) j--;
		if (i < j ){
			swap(arr, i, j);
		}
	}
	
	int k = 0;

	while (k < n && i < n) {
		swap (arr, k, i);
		k += 2;
		i ++;
	}

}

// Utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = {2, 3, -4, -1, 6, -9};

	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
