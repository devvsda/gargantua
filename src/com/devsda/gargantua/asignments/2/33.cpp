/*#include<iostream>

using namespace std;

struct node getTail( struct node* head) {
    while(head != NULL && head->next != NULL) head = head->next;
    return head;
}

void segregate(struct node **head){
    if(*head == NULL || (*head->next == NULL)) return;
    struct node *current = *head;
    struct node *end = getTail(*head);
    struct node *newEnd = end;
    struct node *temp;
    if( ((current->data) % 2) == 0 ) {
        while( current != end && ((current->data) % 2 == 0) ) {
            temp = current->next;
            current->next = NULL;
            end->next = current;
            newEnd = current;
            current = temp;
        }
    }
    else {
        *head = current;
        prev = current;
        while(current != end ) {
            if( (current->data % 2) == 0 ) {
                nextptr = current->next;
                prev->next = nextptr;
                current->next = NULL;
                newEnd->next = current;
                newEnd = current;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    if( (end->data % 2) == 0 ) {
        newEnd->next = current;
        current->next = NULL;
    }
}



*/




#include <stdio.h>
#include <stdlib.h>

/* a node of the singly linked list */
struct node
{
  int data;
  struct node *next;
};
  struct node *getTail( struct node* head) {
    while(head != NULL && head->next != NULL) head = head->next;
    return head;
}

void segregateEvenOdd(struct node **head){
    if((*head) == NULL || ( (*head)->next == NULL)) return;
    struct node *current = *head;
    struct node *end = getTail(*head);
    struct node *newEnd = end;
    struct node *temp;
    if( ((current->data) % 2) == 0 ) {
        while( current != end && ((current->data) % 2 == 0) ) {
            printf("reach\n");
            temp = current->next;
            current->next = NULL;
            end->next = current;
            newEnd = current;
            current = temp;
        }
    }
    else {
        *head = current;
        struct node *prev = current;
        struct node *nextptr;
        while(current != end ) {
            printf("reach\n");
            if( (current->data % 2) == 0 ) {
                nextptr = current->next;
                prev->next = nextptr;
                current->next = NULL;
                newEnd->next = current;
                newEnd = current;
                current = nextptr;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    /*if( (end->data % 2) == 0 ) {
        newEnd->next = current;
        current->next = NULL;
    }*/
}
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of the Doubly Linked List */
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

/* Function to print nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;

  /* Let us create a sample linked list as following
    17->15->8->12->10->5->4->1->7->6 */
  push(&head, 6);
  push(&head, 7);
  push(&head, 1);
  push(&head, 4);
  push(&head, 5);
  push(&head, 10);
  push(&head, 12);
  push(&head, 8);
  push(&head, 15);
  push(&head, 17);

  printf("\n Original Linked list ");
  printList(head);

  segregateEvenOdd(&head);

  printf("\n Modified Linked list ");
  printList(head);

  getchar();
  return 0;
}
