// A C++ program to swap Kth node from beginning with kth node from end
#include <iostream>
#include <stdlib.h>
using namespace std;

// A Linked List node
struct node
{
    int data;
    struct node *next;
};

/* Utility function to insert a node at the beginning */
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Utility function for calculating length of linked list */
int countNodes(struct node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}

/* Function for swapping kth nodes from both ends of linked list */
void swapKth(struct node **head_ref, int k)
{
    int size = countNodes(*head_ref);
    if(k > size) return;
    if(2*k - 1 == size) return;

    struct node *x = *head_ref;
    struct node *xPrev = NULL;

    for(int count = 1; count < k; count++) {
        xPrev = x;
        x = x->next;
    }

    struct node *y = *head_ref;
    struct node *yPrev = NULL;

    for(int count = 1; count < size-k+1; count++) {
        yPrev = y;
        y = y->next;
    }

    if(xPrev) xPrev->next = y;
    if(yPrev) yPrev->next = x;

    struct node *temp = x->next;
    x->next = y->next;
    y->next = temp;

    if(k == 1) *head_ref = y;
    else if(k == n) *head_ref = x;
}

// Driver program to test above functions
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct node *head = NULL;
    for (int i = 8; i >= 1; i--)
       push(&head, i);

    cout << "Original Linked List: ";
    printList(head);

    /*for (int k = 1; k < 10; k++)
    {
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }*/

    swapKth(&head, 5);
    //cout << "\nModified List for k = " << 5 << endl;
    printList(head);


    return 0;
}
