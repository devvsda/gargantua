#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node*right;
};


// A utility function to create a new tree node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}


struct node* convertT2L(struct node *root) {
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    struct node *leftN = convertT2L(root->left);
    struct node* rightN = convertT2L(root->right);
    if(root != NULL ) {
        if(leftN != NULL) {
            leftN->right = root;
            root->left = leftN;
        }
        if(rightN != NULL) {
            rightN->left = root;
            root->right = rightN;
        }
        return rightN;
    }
}

main() {
    // Let us create the tree shown in above diagram
    struct node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    struct node *head = convertT2L(root);

//    while(head->right != NULL) cout << head->data << "  ";
    if(head != NULL) cout << head->data << endl;
    return 0;
}
