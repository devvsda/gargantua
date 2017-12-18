#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

void push (struct node** head_ref, int new_data)
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

void printList(struct node *node)
{
    int count = 0;
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
    printf("\n\n");
}


bool isPalindromeRecur(struct node **left, struct node *right) {
    if(right == NULL) return true;
    bool answer = isPalindromeRecur(left, right->next);
    if(answer == false) return false;

    bool answer1 = ( (*left)->data == right->data );
    (*left) = (*left)->next;
    return answer1;
}

bool isPalindrome(struct node *head) {
    struct node *temp = head;

    return isPalindromeRecur(&temp, temp);
}

main() {
    struct node* head = NULL;

    //push(&head, 1);
    //push(&head, 2);
    //push(&head, 9);
    //push(&head, 4);
    //push(&head, 3);
    //push(&head, 2);
    //push(&head, 1);

    printList(head);

    cout << isPalindrome(head) << endl;

    printList(head);

    return 0;
}
