#include<iostream>

using namespace std;

void findTwoOdd(int arr[], int size){
    int xor1 = 0;
    for(int i = 0; i < size; i++) {
        xor1 = xor1 ^ arr[i];
    }

    xor1 = xor1 & ~(xor1-1);

    int x = 0;
    int y = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] & xor1) x = x ^ arr[i];
        else y = y ^ arr[i];
    }

    printf("%d  %d \n", x, y);
}

 main() {
    return 0;
 }
