#include<iostream>

using namespace std;

int first(int arr[], int start, int end, int value) {
    if(start > end) return -1;
    if(arr[start] == value) return start;
    int mid = start + (end - start)/2;
    if( ( mid == 0 || arr[mid-1] < value) && arr[mid] == value) return mid;
    if(arr[mid] >= value) return first(arr, start, mid-1, value);
    else return first(arr, mid+1, end, value);
}

int last(int arr[], int start, int end, int value) {
    if(start > end) return -1;
    if(arr[end] == value) return end;
    int mid = start + (end - start)/2;
    if(arr[mid] == value && (mid == end || arr[mid + 1] > value) ) return mid;
    if(arr[mid] > value) return last(arr, start, mid-1, value);
    else return last(arr, mid+1, end, value);
}

int countVal(int arr[], int size, int value) {
    if(size == 0) return -1;

    int firstEle = first(arr, 0, size - 1, value);
    if(firstEle == -1) return -1;

    int lastEle = last(arr, 0, size - 1, value);

    printf("first element = %d\nlast element = %d\n", firstEle, lastEle);

    return (lastEle - firstEle + 1);
}
main() {
    int arr[] = {1, 1, 2, 2, 2, 2, 3,};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    cout << countVal(arr, size, x);
    return 0;
}
