#include<iostream>
#include<stdio.h>

using namespace std;

//int i = -1;
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

struct node *insertNode(struct node *root, int key) {
    if(root == NULL) return ( createNode(key));
    if(key < root->key) root->left = insertNode(root->left, key);
    if(key > root->key) root->right = insertNode(root->right, key);
    return root;
}

int addArray(int n, int sum) {
    int s = 0;
    cout << endl;
    for(int i = 0; i <= n; i++) {
        cout << arr[i] << "  ";
        s += arr[i];
    }
    cout << endl << "\t sum of path is  " << s << endl;
    return (s == sum);
}

int hasPathSum(struct node *root, int sum, int pathlen) {
    //int i = -1;
    if(root == NULL) return 0;
    arr[++pathlen] = root->key;
    if( ((root->left) == NULL) && ((root->right) == NULL) ) return (addArray(pathlen, sum));
    return ( hasPathSum(root->left, sum, pathlen) | hasPathSum(root->right, sum, pathlen) );
 }

struct node *findAncestor(struct node *root, int first, int second) {
    if(root == NULL) return NULL;
    if( (first < root->key) && (root->key <= second ) ) {cout << "\n\tancestor  " << root->key << endl; return (root); }
    if(first >= root->key) return findAncestor(root->right, first, second);
    else if(second < root->key) return findAncestor(root->left, first, second);
    //return (root);
}

main() {
    //freopen(stdin, "input", "r");
    int x;
    struct node *root = NULL;
    struct node *temp = NULL;

    for(int i = 0; i < 9; i++) {
        cin >> x;
        root = insertNode(root, x);
    }
   // cout << endl << hasPathSum(root, 45, -1) << endl;
    temp = findAncestor(root, 25, 30);//)->key << endl;
    cout << "\n common ancestor is " << temp->key << endl;
    return 0;
}
