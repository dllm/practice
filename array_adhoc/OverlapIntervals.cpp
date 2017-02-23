#include <iostream>
#include <queue>
using namespace std;


struct Interval
{
	int start, end;
};

bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}



void mergeIntervals (Interval arr[], int n){

	// sort the intervals in increasing order of start time
	sort(arr, arr+n, compareInterval);

	Interval result;

	result.start = arr[0].start;
	result.end = arr[0].end;
	for (int i = 1; i < n; i++){
		if (result.end >= arr[i].start && result.end <= arr[i].end){
			result.end = arr[i].end;
		}
		else {
			cout << result.start <<","<<result.end << endl;
			result.start = arr[i].start;
			result.end = arr[i].end;
		}
	}
	cout << result.start <<","<<result.end << endl;


}

// Driver program
int main()
{
	Interval arr[] =  { {6,8}, {1,3}, {2,4}, {5,7}, {9,10} };
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}



