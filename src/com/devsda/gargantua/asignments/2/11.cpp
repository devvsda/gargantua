#include<isotream>

using namespace stdd;

struct node *removeOutsideRange(struct node *root, int min, int max) {
        if(root == NULL) return NULL;
        struct node *left = removeOutsideRange(root->left, min, max);
        struct node *right = removeOutsideRange(root->right, min, max);

        if(root->data < min) {
            struct node *right = root->right;
            delete(root);
            return right;
        }
        if(root->data > max) {
            struct node *left = root->left;
            delete(root);
            return left;
        }
        return root;
}


main() {
    return 0;
}
