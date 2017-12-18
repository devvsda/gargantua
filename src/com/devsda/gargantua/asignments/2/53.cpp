#include<iostream>

using namespace std;

void swap(int *a, int *b) {  (*a) = (*a)^(*b); (*b) = (*a)^(*b); (*a) = (*a)^(*b); }

void segregate_0_1(int arr[], int size) {
    int j = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i] == 0) {
            swap(&arr[i], &arr[++j]);
        }
    }
}

main() {
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    segregate_0_1(arr, size);
    for(int i = 0; i < size; i++) cout << arr[i] << "  ";
    return 0;
}
