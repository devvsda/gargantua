#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct node {
    long long key;
    struct node *left;
    struct node *right;
    long long height;
    long long size;
    long long frequency;
};

long long height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

long long size(struct node *N) {
    if (N == NULL)
        return 0;
    return N->size;
}

long long max(long long a, long long b) {
    return (a > b)? a : b;
}

long long getFrequency(struct node *N) {
    if(N == NULL) return 0;
    return N->frequency;
}

struct node* newNode(long long key) {
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    node->size = 1;
    node->frequency = 1;
    return(node);
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    y->size = size(y->left) + size(y->right) + getFrequency(y);
    x->size = size(x->left) + size(x->right) + getFrequency(x);
    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    x->size = size(x->left) + size(x->right) + getFrequency(x);
    y->size = size(y->left) + size(y->right) + getFrequency(y);
    return y;
}

long long getBalance(struct node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert( struct node* node, long long key ) {
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)    node->left  = insert(node->left, key);
    else if(key > node->key)    node->right = insert(node->right, key);
    else node->frequency += 1;

    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + getFrequency(node);

    long long balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printInorder(struct node *root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << " { " << root->key << " " << root->frequency <<  " }";
    printInorder(root->right);
}

void findMax( struct node *root, struct node **maxNode ) {
    while(root->right != NULL) {
        root = root->right;
    }
    *maxNode = root;
}

struct node* deleteNode(struct node* root, long long key) {
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else {
        struct node *temp = root->left ? root->left : root->right;

        if(temp == NULL) {
            temp = root;
            root = NULL;
        }
        else *root = *temp;
        free(temp);
    }

    if (root == NULL)
      return root;

    root->height = max( height(root->left), height(root->right) ) + 1;
    root->size   = size(root->left) + size(root->right) + getFrequency(root);

    long long balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

main() {
    //freopen ( "input.txt", "r", stdin );
    long long n;
    long long value;
    long long X;
    struct node *maxNode;
    long long minCost = 0;
    long long originValue = 0;
    long long firstOperationIteration;
    struct node *root = NULL;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> value;
        if(value < 0) root = insert(root, value);
    }

    cin >> X;


    while(size(root) > 0) {
        /*cout << "PrintInorder\n";
        printInorder(root);
        cout << endl;
        cout << "Size of Tree : " << root->size << endl;*/
        findMax(root, &maxNode);
        //cout << "MAxNode Information : " << maxNode->key << " " << maxNode->frequency << endl;
        firstOperationIteration = (abs(maxNode->key + originValue));
        //cout << "firstOperationIteration : " << firstOperationIteration << endl;
        //cout << "First Operatrion Used : " << firstOperationIteration*X << endl;
        //cout << "Second Operation Used : " << (root->size)*firstOperationIteration << endl;
        minCost = minCost + min( firstOperationIteration*X, (root->size)*firstOperationIteration );
        //cout << "MinCost Information : " << minCost << endl;
        originValue = originValue + firstOperationIteration;
        //cout << "OriginValue Update : " << originValue << endl;
        root = deleteNode(root, maxNode->key);
         //cout << "===============\n\n";
    }

    cout << minCost << endl;

    return 0;
}
