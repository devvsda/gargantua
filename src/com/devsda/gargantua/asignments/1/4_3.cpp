#include<iostream>
#include<stdio.h>

using namespace std;

int arr[100];

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *createNode(int key) {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertArray(int arr[], int start, int end) {
    if(end < start) return NULL;

    int mid = (start + end)/2;
    struct node *n = createNode(arr[mid]);
    n->left = insertArray(arr, start, mid - 1);
    n->right = insertArray(arr, mid + 1, end);
    return n;
}

void preorder(struct node *root) {
    if(root != NULL) {
        cout << root->key << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->key << "  ";
        inorder(root->right);
    }
}

main() {
    int n;
    cin >> n;
    struct node *root = NULL;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    root = insertArray(arr, 0, n-1);
    cout << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}
