#include<iostream>

using namespace std;

int toSumTree(struct node *node) {
    if(node == NULL) return 0;
    int old_val = node->data;
    node->data = toSumTree(node->left) + toSumTree(node->right);
    return old_val + node->data;
}

main() {

}
