#include<iostream>

using namespace std;

int merge(int arr[], int start, int mid, int end) {
    int leftSize = mid-start+1;
    int rightSize = end-mid;
    int left[leftSize];
    int right[rightSize];
    for(int i = 0; i < leftSize; i++) left[i] = arr[start + i];
    for(int i = 0; i < rightSize; i++) right[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = start;
    int count = 0;


    while(i < leftSize && j < rightSize) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
            count = count + (mid - i + 1);
        }
    }

    while(i < leftSize) arr[k++] = left[i++];
    while(j < rightSize) arr[k++] = right[j++];

    return count;
}

int mergeSort(int arr[], int start, int end ) {
    if(start >= end) return 0;
    int count = 0;
    int mid = start + (end - start)/2;
    cout << "End is : " << end << endl;
    count = mergeSort(arr, start, mid);
    count = count + mergeSort(arr, mid+1, end);
    count = count + merge(arr, start, mid, end);
    return count;
}


main() {
    int arr[] = {1, 20, 6, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "\nAnswer : " << mergeSort(arr, 0, size-1);
    return 0;
}
