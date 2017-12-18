#include<iostream>

using namespace std;

/**
* pre - preOrder array
* post - postOrder array
* preIndex - current Index of pre array
* l -
* h -
* size - size of array
**/

struct node* constructTreeUtil (int pre[], int post[], int* preIndex, int l, int h, int size) {
    if(*preIndex > size || l > h) return NULL;
    struct node *root = newNode(pre[*preIndex]);
    (*preIndex)++;
    if(l == h) return root;
    int i;
    for(i = l; i <= h; i++) {
        if(post[i] == pre[*preIndex]) break;
    }
    if(i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i+1, h, size);
    }
    return root;
}
main() {
    return 0;
}
