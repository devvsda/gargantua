#include<iostream>
#include<string>

using namespace std;

int ans = 0;

int findMissing(int arr[], int index[], int size, int shift) {
    if(size == 0) return 0;
    cout << "jai\n";
    int j = 0;
    int k = 0;
    int odd[100];
    int even[100];

    for(int i = 0; i < size; i++) {
        if(arr[index[i]] & 1) odd[j++] = index[i];
        else even[k++] = index[i];
        arr[index[i]] = arr[index[i]] >> 1;
    }

    if(k >= j) {
        //s = '0' + s;
        ans = ans;
        ++shift;
        findMissing(arr, even, k, shift);
    }
    else {
        //s = '1' + s;
        ans = ans + (1 << (++shift));
        findMissing(arr, odd, j, shift);
    }
    return (ans);
}

main() {
    int index[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << endl << findMissing(arr, index, 8, 0);
    return 0;
}
