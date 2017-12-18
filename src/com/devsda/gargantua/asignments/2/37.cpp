#include<iostream>

using namespace std;

void splitLL(struct node *head, struct node **first, struct node **second) {
    if( head == NULL || head->next == NULL ) {
        *first = head;
        *second = NULL;
        return;
    }
    struct node *fast = head;
    struct node *slow = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

struct node *sortedMerge(struct node *a, struct node *b) {
    if(a == NULL) return b;
    if(b == NULL) return a;

    struct node *result;
    if(a->data < b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(struct node **headRef) {
    if(*headRef == NULL || *headRef->next == NULL) return;
    struct node *a;
    struct node *b;

    splitLL(*headRef, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);

}
main() {
    return 0;
}
