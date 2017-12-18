#include<iostream>

using namespace std;

int maxDiff(int arr[], int size) {
    int maxDiff = arr[1] - arr[0];
    int min = arr[0];

    for(int i = 1; i < size; i++) {
        if(maxDiff < arr[i] - min) {
            maxDiff = arr[i] - min;
        }

        if(arr[i] < min) {
            min = arr[i];
        }
    }

    return maxDiff;
}

main() {
    return 0;
}
