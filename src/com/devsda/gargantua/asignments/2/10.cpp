#include<iostream>

using namespace std;

//void printString(int inpuut[], int currentIndex, int size) {
//    if
//}
// data = 0, pString = "", arr = array of Alphabet

struct node *createTree(int data, String pString, int[] arr) {
    if(data > 26) return NULL;

    string parent = pString + alphabeet[data];
    struct node *root = newNode(parent);
    if(arr.length != 0) {
        data = arr[0];
        root->left = createTree(data, parent, arr+1);
        if(arr.length > 1) {
            data = arr[0]*10 + arr[1];
            root->right = createTree(data, parent, arr+2);
        }
    }
    return root;
}

main() {
    return 0;
}
