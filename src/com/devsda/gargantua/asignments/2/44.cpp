//Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
//Output: 3 (1-> 3 -> 8 ->9)

#include<iostream>


using namespace std;

#define TRAP (1 << 16)

int minJumps(int arr[], int size) {

    if(arr[0] == 0) return -1;

    int output[size];
    for(int i = 0; i < size; i++) { output[i] = TRAP; }
    output[0] = 0;
    int j;
    for(int i = 0; i < size; i++) {
        j = i+1;
        if(arr[i] == 0) { continue; }
        while(j < size && j <= i+arr[i]) {
            if(output[i] != TRAP &&
               output[j] > output[i] + 1) {
                output[j] = output[i] + 1;
            }
            j++;
        }
    }
    return output[size-1];
}

main() {
    //int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int arr[]= {1, 0, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << minJumps(arr, size);
    return 0;
}
