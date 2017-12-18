#include<iostream>

using namespace std;

struct node *getNext(struct node *node) {
    struct node *temp = node->nextRight;
    while(temp != NULL) {
        if(temp->left != NULL) return temp->left;
        if(temp->right != NULL) return temp->right;
        temp = temp->nextRight;
    }
    return NULL;
}

void connectNextRight(struct node *root) {
    if(root == NULL) return;
    struct node *current = root;
    struct node *temp;

    while(current != NULL) {
            temp = current;
            while(temp != NULL) {
                if(temp->left != NULL) {
                    if(temp->right != NULL) {
                        temp->left->nextRight = temp->right;
                        temp->right->nextRight = getNext(temp);
                    }
                    else {
                        temp->right->nextRight = getNext(temp);
                    }
                }
                else if(temp->right != NULL) {
                    temp->right->nextRight = getNext(temp);
                }
                temp = temp->nextRight;
            }
            if(currrent->left != NULL) current = current->left;
            else if(current->right != NULL) current = current->right;
            else current = current->nextRight;
    }
}


main() {
    return 0;
}
