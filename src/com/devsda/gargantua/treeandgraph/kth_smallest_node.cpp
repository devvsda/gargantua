#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    int size;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int size(struct node* node) {
    if(node == NULL) return 1;
    else return ( ((node->left)?node->left->size:0) + ((node->right)?node->right->size:0) + 1);
}

struct node *addNode(struct node *head, int data) {
    if(head == NULL ) return newNode(data);
    if(data < head->data) head->left = addNode(head->left, data);
    if(data > head->data) head->right = addNode(head->right, data);
    head->size = size(head->left) + size(head->right) + 1;
    return head;
}

void display(struct node *head) {
    if(head == NULL) return;
    display(head->left);
    cout << "\n " << head->data << "  " << head->size;
    display(head->right);
}

/*/int smallest(struct node *head, int k, int sze) {
    if(head == NULL) return 0;

    if(head->size == k + 1) return max(head->left);
    else if(k > head->left->size) smallest(head->left, k, sze);
    else if(k < head->left->size) smallest(head->left, sze-k, sze);

}*/
struct node* smallest(struct node* t,int k)
    {
        int left_size = 0;
        if(t->left!=NULL) left_size = t->left->size;
        if(left_size+1==k) return t;
        else if(k<=left_size) return smallest(t->left,k);
        else return smallest(t->right,k-left_size-1);//find k-left_size-1 smallest in right subtree.
    }

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    int x;
    struct node *head = NULL;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        head = addNode(head, x);
    }

    display(head);

    cout << "\n" << smallest(head, 3)->data;
    return 0;
}
