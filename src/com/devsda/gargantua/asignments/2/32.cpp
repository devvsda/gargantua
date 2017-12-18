#include<iostream>

using namespace std;

struct node *getMid(struct node *root, struct node **prevMid) {
    if(root == NULL ) return NULL;
    struct node *fast =  root;
    struct node *slow = root;

    while(fast->next != NULL && fast->next->next != NULL) {
        prevMid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next != NULL) return prevMid->next;
    return prevMid;
}

struct node *dll2Bst(struct node *root, struct node *prevMid) {
    if(root == NULL) return NULL;
    struct node *prev = getMid(root, &prevMid);
    if(prev != NULL) struct node *newNode = createNode(->data);
    newNode->left = dll2Bst()
}
main() {
    return 0;
}
