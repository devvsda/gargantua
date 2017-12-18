#include<iostream>

using namespace std;

struct tnode {
    int data;
    struct tnode* left;
    struct tnode *right;
};

struct snode {
    struct tnode *node;
    struct snode *next;
};

void push(struct snode **snod, struct tnode*node) {
    struct snode* newNode = (struct snode*)malloc(sizeof(struct snode));
    newNode->node = node;
    newNode->next = *snod;
    *snod = newNode;
}

struct tnode *pop(struct snode **stack) {
    struct snode* snod;
    struct tnode* tnod;
    snod = *stack;
    tnod = snod->node;
    *stack = (*stack)->next;
    delete(snod);
    return tnod;
}

int isEmpty(struct snode*  head) {
    if(head == NULL) return 1;
    return 0;
}

void inOrderTraversal(struct tnode* root){
    int done = 0;
    struct tnode* current = root;
    struct snode *stack = NULL;

    while(!done) {
        if(current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        else {
            if(!isEmpty(stack)) {
                struct tnode *node = pop(&stack);
                cout << node->data << "  ";
                current = node->right;
            }
            else {
                done = 1;
            }
        }
    }
}

struct tnode* newtNode(int data)
{
  struct tnode* tnode = (struct tnode*)
                       malloc(sizeof(struct tnode));
  tnode->data = data;
  tnode->left = NULL;
  tnode->right = NULL;

  return(tnode);
}

main() {
    struct tnode *root = newtNode(1);
    root->left        = newtNode(2);
    root->right       = newtNode(3);
    root->left->left  = newtNode(4);
    root->left->right = newtNode(5);
    inOrderTraversal(root);
    return 0;
}
