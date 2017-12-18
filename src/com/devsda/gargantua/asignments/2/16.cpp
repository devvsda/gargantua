#include<iostream>

using namespace std;

struct node* constructTreeUtil (int pre[], int* preIndex, int low, int high, int size) {
    if(*preIndex > size || low > high) return NULL;

    struct node *root = newNode(pre[*preIndex]);
    (*preIndex)++;
    if(low == high) return root;

    int i;
    for(i = low;; i < high; i++) {
        if(pre[i] > root->data) break;
    }

    root->left = constructTreeUtil(pre, preIndex, low, i-1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);
    return root;
}




struct node* constructTreeUtil( int pre[], int* preIndex, int key, int min, int max, int size ) {
    if(*preIndex > size) return NULL;
    struct node *root = NULL;
    if( key > min && key < max) {
        root = newNode(pre[*preIndex]);
        (*preIndex)++;
        //if(min == max) return root;
        if(*preIndex < size) {
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, root->data, size);
            root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], root->data, max, size);
        }
    }
    return root;
}
