#include<iostream>

using namespace std;

void postOrder(struct node *root, int key) {
    stack<node *> stck;
    while(1) {
        while(root && root->data != key) {
            stck.push(root);
            root = root->left;
        }

        if(root && root->data  == key) break;

        if( !stck.empty() && stck.top()->right == NULL ) {
            root = stck.pop();

            while( !stck.empty() && stck.top->right == root ) {
                root = stck.pop();
            }
        }

        root = ( stck.empty() ) ? (NULL) : stck.top->right;
    }
}

main() {
    postOrder(struct node *root, int key);
    return 0;
}
