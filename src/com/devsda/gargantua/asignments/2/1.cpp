#include<iostream>
#include<cstdio>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void printArray(int val, int array[], int sze) {
    cout << val << " ---> ";
    for(int i = sze-1; i >= 0; i--) {
        cout << array[i] << "  ";
    }
    cout << endl;
}

void func(struct node *root, int array[], int currentIndex) {
    if(root == NULL) return;
    array[currentIndex++] = root->data;
    printArray(root->data, array, currentIndex);
    func(root->left, array, currentIndex);
    func(root->right, array, currentIndex);
}

// A utility function to create a new tree node
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


main() {
    int array[1000];
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);

    printf("Following are all keys and their ancestors\n");
    func(root, array, 0);
    return 0;
}
