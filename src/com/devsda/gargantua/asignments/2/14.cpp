#include<iostream>

using namespace std;

void insert(struct node **root, int data, struct Queue* queue) {
    struct node *temp = newNode(data);

    if(!*root) *root = temp;
    else {
        if(front(queue)->left == NULL) {
            front(queue)->left = temp;
        }
        else if(front(queue)->right == NULL){
            front(queue)->right = temp;
        }

        if( hasBothChildren(front(queue))) {
            dequeue(&queue);
        }
    }
    enqueue(&queue, temp);
}
