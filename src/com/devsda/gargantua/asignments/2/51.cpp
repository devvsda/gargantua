#include<iostream>

using namespace std;

int floor(int arr[], int start,int end, int value) {
    if(start > end) return -1;
    //if(start == end) if(arr[start] < value) return arr[start]; else return -1;
    if(arr[start] >= value) return -1;
    if( arr[end] < value) return arr[end];
    int mid = start + (end - start)/2;
    if( (mid == end || arr[mid + 1] >= value) && arr[mid] < value) return arr[mid];
    if(arr[mid] >= value) return floor(arr, start, mid, value);
    else return floor(arr, mid+1 , end, value);
}

int ceil(int arr[], int start, int end, int value) {
    if(start > end) return -1;

    if(arr[start] >= value) return arr[start];
    if(arr[end] < value) return -1;

    int mid = start + (end - start)/2;

    if( ( mid == 0 || arr[mid-1] < value) && arr[mid] >= value) return arr[mid];

    if(arr[mid] < value) return ceil(arr, mid+1, end, value);
    else return ceil(arr, start, mid-1, value);
}

main() {
    int arr[] = {3, 6, 9, 12, 45, 789};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << ceil(arr, 0, size-1, 7);
    return 0;
}
