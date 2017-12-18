// Quick sort.

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int arr[100];

void printArray(int start, int end, string tag) {
	cout <<  tag << "\n";

	for(int i = start; i < end; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int shuffle(int start, int end) {

	printArray(start, end+1, "Before Intermediate step");

	int pivot = arr[end];

	int lastIndexOfLeftWindow = start-1;

	for(int itr = start; itr < end; itr++) {
		if(arr[itr] < pivot) {
			lastIndexOfLeftWindow++;
			swap(arr[itr], arr[lastIndexOfLeftWindow]);
		}
	}

	swap(arr[lastIndexOfLeftWindow+1], arr[end]);

	printArray(start, end+1, "After Intermediate step");

	return lastIndexOfLeftWindow+1;
}

void quickSort(int start, int end) {
	if(start >= end) return;
	int pivotIndex = shuffle(start, end);
	quickSort(start, pivotIndex-1);
	quickSort(pivotIndex+1, end);
}

int main() {
	int N, value;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> value;
		arr[i] = value;
	}
	
	printArray(0, N, "Before sorting");

	quickSort(0, N-1);

	printArray(0, N, "After sorting");

	cout << "Jai mata di";
	return 0;
}