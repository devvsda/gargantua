#include<iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int x) {
    if(start > end) return -1;

    int mid = start + (end - start)/2;
    //if(mid == 0 && arr[mid] == x) return mid;
    if(((mid == 0) || (arr[mid - 1] < x)) && (arr[mid] == x)) return mid;
    else if(arr[mid] > x) return binarySearch(arr, start, mid-1, x);
    else return binarySearch(arr, mid + 1, end, x);
}


int main() {
    int n;
    cin >> n;
    int arr[n];// = {1, 2, 3, 3, 5, 7};

    for(int i=0;i<n;i++) cin >> arr[i];
    int x;
    cin >> x;
    cout << binarySearch(arr, 0, n-1, x);
    return 0;
}

