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

void merge(int start, int mid, int end) {

	int a[mid-start+1];
	int b[end-mid];

	int j = 0, i = 0;
	for(i = start; i <= mid; i++) a[j++] = arr[i];
	j = 0;
	for(i = mid+1; i <= end; i++) b[j++] = arr[i]; 

	i = j = 0;
	int k = start;
	while(i < mid-start+1 && j < end-mid) {
		if(a[i] <= b[j]) {
			arr[k++] = a[i++];
		} else {
			arr[k++] = b[j++];
		}
	}

	while(i < mid-start+1) arr[k++] = a[i++];
	while(j < end-mid) arr[k++] = b[j++]; 
}

void mergeSort(int start, int end) {
	if(start >= end) return;

	printArray(start, end, "Before processing");

	int mid = start + (end - start)/2;

	mergeSort(start, mid);
	mergeSort(mid+1, end);

	merge(start, mid, end);

	printArray(start, end, "Before processing");
}

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	printArray(0, N-1, "Input array");

	mergeSort(0, N-1);

	printArray(0, N-1, "Output array");

	return 0;
}