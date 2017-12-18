#include<iostream>

using namespace std;

// First Approach

void printCombinatorials(int arr[], int start, int end, int data[], int index, int size) {
    if(index == size) {
        for(int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    for(int j = start, j <= end && ((size - index) >= (end - j + 1)); j++) {
        data[index] = arr[j];
        printCombinatorials(arr, j+1, end, data, index+1, size);
    }
}

// Second Approach

void printCombinatorials(int arr[], int start, int end, int data[], int index, int size) {
    if(index == size) {
        for(int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        return ;
    }

    if(strat > end) return;

    data[index] = arr[start];
    printCombinatorials(arr, start+1, end, data, index+1, size);

    printCombinatorials(arr, start, end, data, index+1, size);
}

 main() {
    return 0;
 }
