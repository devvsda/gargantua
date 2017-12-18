#include<iostream>

using namespace std;

struct node {
    struct node *left;
    struct node *right;
    int data;
};

void printK(struct node *root, int K) {
    if(root == NULL) return;

    if(K == 0) { cout << root->data << " "; return; }

    printK(root->left, K-1);
    printK(root->right, K-1);
}

void printKDistantNodes(struct node *root, struct node *givenNode, int K) {
    static int distance = 0;
    if(root == NULL) return;

    if(root->data < givenNode->data) {
        printKDistantNodes(root->right, givenNode, K);
        distance++;
        if(K == distance) cout << root->data << " ";
        else printK(root->left, K-distance-1);
    }
    else if(root->data > givenNode->data) {
        printKDistantNodes(root->left, givenNode, K);
        distance++;
        if(K == distance) cout << root->data <<  " ";
        else printK(root->right, K-distance-1);
    }
    else {
        printK(root, K);
        return;
    }
}

main() {
    return 0;
}
