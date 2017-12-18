#include<iostream>

using namespace std;

struct node *reverseK(struct node *head, int k) {
    if(node == NULL) return NULL;
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next;
    int count = 0;

    while(current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(head != NULL) head->next = current;
    count = 1;
    while(current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if(current != NULL) current->next = reverseK(current->next, k);
    return prev;
}

main() {
    return 0;
}
