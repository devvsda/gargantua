#include<iostream>

using namespace std;

void printArray(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void printAllBrackets(char arr[], int i, int size, int m, int n) {
    if(m > n) return;
    if(i == size) {
        printArray(arr, size);
        return;
    }

    if(m > 0) {
        arr[i] = '{';
        printAllBrackets(arr, i+1, size, m-1, n);
    }
    if(n > 0) {
        arr[i] = '}';
        printAllBrackets(arr, i+1, size, m, n-1);
    }
}

main() {
    char arr[100];
    printAllBrackets(arr, 0, 6, 3, 3);
    return 0;
}
