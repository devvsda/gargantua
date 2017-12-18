 //(A(B(D)(E))(C(F)(G)))

#include<iostream>
#include<string>

using namespace std;

struct node {
    struct node *left;
    struct node *right;
    char data;
};

string str = "(A(B)(C))";//"(A(B(D)(E))(C(F)(G)))";

//index == 0

struct node *newNode(char input) {
    struct node *_newNode = (struct node *)malloc(sizeof(struct node));
    _newNode->left = _newNode->right = NULL;
    _newNode->data = input;
    return _newNode;
}

struct node* createTree(int index) {

    struct node *root = NULL;

    if(str[index] == '(') {
        root = newNode(str[index+1]);
        root->left = createTree(index+2);
        if(str[index] == ')') return root;
    }

    return root;
}

main() {
    createTree(0);
    return 0;
}
