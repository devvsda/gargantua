#include<iostream>

using  namespace std;

void connectAllLeafDLL(struct node *root, struct node **prev) {
    if(root == NULL) return;
    if(root->right == NULL && root->left == NULL) {
        if(*prev != NULL) {
            (*prev)->left = root;
        }
        *prev = root;
    }
    connectAllLeafDLL(root->right, prev);
    connectAllLeafDLL(root->left, prev);
}

void connectAllLeafDLL(struct node *root) {
    if(root == NULL ) return;
    struct node *prev = NULL;
    struct node *current = NULL;
    struct node *next = NULL:

    connectAllLeafLEftPointer(root, &prev);
    //if(prev != NULL) prev->left = NULL;
    current = RightMostLEaf(root);
    prev = NULL;

    while(current != NULL) {
        current->right = prev;
        prev = current;
        current = current->left;
    }
}

main() {
    return 0;
}
