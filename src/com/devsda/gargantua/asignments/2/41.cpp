#include<iostream>

using namespace std;

int ceilSearch(int arr[], int start, int end, int key) {
    if(start > end) return -1;

    if(arr[start] >= key) return start;
    if(arr[end] < key) return -1;

    int mid = start + (end - start)/2;

    if( mid > start && arr[mid-1] < key && arr[mid] >= key ) return mid;
    if(arr[mid] < key && mid < end && arr[mid + 1] >= key) return mid+1;

    if(arr[mid] < key) return ceilSearch(arr, mid + 1, end, key);
    else return ceilSearch(arr, start, mid - 1, key);
}

main() {
    int arr[] = {1, 4, 7, 8, 9, 15};
    int sze = sizeof(arr)/sizeof(arr[0]);
    cout << ceilSearch(arr, 0, sze-1, 2);
    return 0;
}
