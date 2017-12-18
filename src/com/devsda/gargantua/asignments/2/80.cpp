#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* A linked list node */
struct node
{
    int data;
    struct node *next;
};

/* Function to pairwise swap elements of a linked list.
   It returns head of the modified list, so return value
   of this node must be assigned */


struct node *pairWiseSwap(struct node *head) {
    if(head == NULL || head->next == NULL) return head;
    struct node *second = head->next;
    struct node *third = second->next;
    second->next = head;
    head->next = pairWiseSwap(third);
    return second;
}

/*struct node *pairWiseSwap(struct node* head)
{
    // Base Case: The list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;

    // Store head of list after two nodes
    struct node* remaing = head->next->next;

    // Change head
    struct node* newhead = head->next;

    // Change next of second node
    head->next->next = head;

    // Recur for remaining list and change next of head
    head->next = pairWiseSwap(remaing);

    // Return new head of modified list
    return newhead;
}
 */


/* Function to add a node at the begining of Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Druver program to test above function */
int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);

    start = pairWiseSwap(start);  // NOTE THIS CHANGE

    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);

    return 0;
}
/*
void pairWiseSwap(struct node **head) {
    if(*head == NULL || *head->next == NULL) return;

    struct node *prev = *head;
    struct node *curr = *head->next;

    *head = curr;

    while(curr != NULL) {
        struct node *nxt = curr->next;
        curr->next = prev;
        if(nxt == NULL || nxt->next == NULL) {
            prev->next = nxt->next;
            break;
        }
        prev->next = nxt->next;
        prev = nxt;
        curr = prev->next;
    }
}

*/


