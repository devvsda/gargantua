#include<iostream>

using namespace std;

void swap(int *a, int *b) {  (*a) = (*a)^(*b); (*b) = (*a)^(*b); (*a) = (*a)^(*b); }

void swapPortion(int arr[], int startI, int startII, int size) {
    int i = startI;
    int j = startII;
    int count = 0;
    while(count < size) {
        swap( &arr[i++], &arr[j++] );
        count++;
    }
}
void leftRotate(int arr[], int d, int n) {
    if(d == 0 || d == n) return;
    if(d == n-d) {
        swapPortion(arr, 0, n-d, d);
        return;
    }
    if(d < n-d) {
        swapPortion(arr, 0, n-d, d);
        leftRotate(arr, d, n-d);
    }
    else if(d > n-d){
        swapPortion(arr, 0, d, n-d);
        leftRotate(arr + n - d, 2*d - n, d);
    }
}
main() {
    return 0;
}
