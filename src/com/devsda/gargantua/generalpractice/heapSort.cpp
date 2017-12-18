#include<iostream>

using namespace std;

int arr[100];

int endIndex;

void printArray(int start, int end, string tag) {
	cout <<  tag << "\n";

	for(int i = start; i < end; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int leftChild(int parent) {
	return 2*parent + 1;
}

int rightChild(int parent) {
	return 2*parent + 2;
}

void maxHeapify(int root, int maxRange) {
	int left = leftChild(root);
	int right = rightChild(root);

	int largest = root;

	if(left <= maxRange && arr[root] < arr[left]) {
		largest = left;
	}

	if(right <= maxRange && arr[largest] < arr[right]) {
		largest = right;
	}

	if(largest != root) {
		swap(arr[largest], arr[root]);
		maxHeapify(largest, maxRange);
	}
}

void buildHeap(int start, int end) {
	
	int mid = start + (end-start)/2;
    
    for(int i = mid; i >= 0; i--) {
    	maxHeapify(i, end);
    }
}

void heapSort(int start, int end) {
	buildHeap(start, end);

	printArray(start, end+1, "After building heap");

	endIndex = end - start;

	for(int i = start; i <= end; i++){
		swap(arr[0], arr[endIndex--]);
		maxHeapify(0, endIndex);
		printArray(start, end+1, "After  iteration.");
	}
}

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	printArray(0, N-1, "Input array");

	heapSort(0, N-1);

	printArray(0, N-1, "Output array");

	return 0;
}