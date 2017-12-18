// MergeSort
#include<iostream>

using namespace std;

int arr[100];

void printArray(int start, int end, string tag) {
	cout <<  tag << "\n";

	for(int i = start; i < end; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void insertionSort(int start, int end) {
	
	for(int itr = start+1; itr <= end; itr++) {
		int startIndex = itr-1;
		int value = arr[itr];
		while(startIndex >= 0 && arr[startIndex] > value) {
			arr[startIndex+1] = arr[startIndex];
			startIndex--;
		}

		arr[startIndex+1] = value;

		printArray(start,end+1,"After iteration");
	}
}

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	printArray(0, N, "Input array");

	insertionSort(0, N-1);

	printArray(0, N, "Output array");

	return 0;
}