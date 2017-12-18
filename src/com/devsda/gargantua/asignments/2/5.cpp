#include<iostream>

using namespace std;

struct node *convertT2L(struct node *root) {
    if(root == NULL) return NULL;

    if(root->left != NULL) {
        struct node *left = convertT2L(root->left);

        while(left->right != NULL) left = left->right;

        left->right = root;
        root->left = left;
    }
    if(root->right != NULL) {
        struct node *right = convertT2L(root->right);

        while(right->left != NULL) right = right->left;

        right->left = root;
        root->right = right;
    }
    return root;
}
main() {
    return 0;
}
