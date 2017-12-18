/**
* Given a matrix mxn,
* where all the rows were sorted, print the elements in the matrix in a sorted order.
**/

#include<iostream>
#include<vector>

#define ROW 5
#define COLUMN 4

using namespace std;

void mergeArrays(int input[][4], int start, int mid, int end) {
    int sizeLeft = (mid-start)*COLUMN;
    int sizeRight = (end-mid+1)*COLUMN;

    int left[sizeLeft];
    int right[sizeRight];

    int k = 0;
    int i, j;

    for(i = start; i < mid; i++) {
        for(j = 0; j < COLUMN; j++) {
            left[k++] = input[i][j];
        }
    }

    k = 0;
    for(i = mid; i <= end; i++) {
        for(j = 0; j < COLUMN; j++) {
            right[k++] = input[i][j];
        }
    }

    i = 0;
    j = 0;

    k = start;
    int l = 0;

    while(i < sizeLeft && j < sizeRight) {
        if(left[i] < right[j]) {
            input[k][l] = left[i];
            ++i;
            ++l;
        }
        else {
            input[k][l] = right[j];
            ++j;
            ++l;
        }
        if(l == COLUMN) {
            ++k;
            l = 0;
        }
    }

    while(i < sizeLeft) {
        input[k][l] = left[i];
        ++i;
        ++l;
        if(l == COLUMN) {
            ++k;
            l = 0;
        }
    }

    while(j < sizeRight) {
        input[k][l] = right[j];
        ++j;
        ++l;
        if(l == COLUMN) {
            ++k;
            l = 0;
        }
    }
}

void makeSortedArray(int input[][4], int start, int end) {
    if(start >= end) return;
    int mid = start + (end - start)/2;
    makeSortedArray(input, start, mid);
    makeSortedArray(input, mid+1, end);
    mergeArrays(input, start, mid+1, end);
}
main() {
    int input[][4] = { {2, 6, 9, 34}, {1, 34, 56, 78}, {12, 24, 45, 67}, {11, 112, 234, 456}, {9, 19, 29, 39} };

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++) {
            cout << input[i][j] <<"  ";
        }
        cout << endl;
    }
    //int *temp = (int *)malloc( sizeof(int)*(M*N + 1) );
    makeSortedArray(input, 0, 4);

    cout << endl << endl;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++) {
            cout << input[i][j] <<"  ";
        }
        cout << endl;
    }
    return 0;
}
