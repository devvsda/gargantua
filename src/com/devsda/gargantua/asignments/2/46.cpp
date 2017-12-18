#include<iostream>

using namespace std;

int minDistance(int arr[], int size, int x, int y ) {

    int j;
    int prev;
    int i = 0;
    int min = INT_MAX;
    while(i < size && arr[i] != x && arr[i] != y) { i++; }
    prev = i;
    for(i = i+1; i < size; i++) {
        if(arr[i] == x || arr[i] == y) {
            if(arr[i] != arr[prev]) {
                if(min > i - prev) min = i - prev;
                prev = i;
            }
            else prev = i;
        }
    }

}

main() {
    return 0;
}
