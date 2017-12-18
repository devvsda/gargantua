#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int start, int end, int val) {

    if(start <= end) {
        int mid = (start + end)/2;
        if(arr[mid] == val) return mid;
        if( val > arr[mid]) return (binarySearch(arr, mid+1, end, val));
        if(val < arr[mid]) return (binarySearch(arr, start, mid-1, val));
    }
    else return end+1;
}

main() {
    int arr[] = {2, 4, 6, 10, 11, 89};
    printf( "%d", binarySearch(arr, 0, 5, 7));
    delete []arr;
    return 0;
}
