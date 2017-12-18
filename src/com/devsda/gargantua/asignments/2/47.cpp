#include <stdio.h>
#include <limits.h>  // For INT_MAX
#include<iostream>

using namespace std;

int minDist(int arr[], int size, int x, int y ) {

    int j;
    int prev;
    int i = 0;
    int min = INT_MAX;
    while(i < size && arr[i] != x && arr[i] != y) { i++; }
    //cout << i;
    prev = i;
    for(i = i+1; i < size; i++) {
        if(arr[i] == x || arr[i] == y) {
            if(arr[i] != arr[prev]) {
                if(min > (i - prev)) {
                    min = (i - prev);
                    //cout << "\n\t\tmin = " << min << endl;
                }
                prev = i;
            }
            else prev = i;
        }
    }
    return min;

}

/* Driver program to test above fnction */
int main()
{
    int arr[] ={3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 6;

    printf("Minimum distance between %d and %d is %d\n", x, y,
            minDist(arr, n, x, y));

    //cout << minDist(arr, n, x, y);
    return 0;
}
