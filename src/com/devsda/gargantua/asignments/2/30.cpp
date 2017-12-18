#include<iostream>

using namespace std;

struct node *mergeChildSort(node node *head1, struct node *head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    struct node *result; // = (struct node *)malloc(sizeof(struct node));
    if(head1->data < head2->data) {
        result = head1;
        result->down = mergeChildSort(head1->down, head2);
    }
    else {
        result = head2;
        result->down = mergeChildSort(head1, head2->down);
    }
    return result;
}

struct node *mergeSort(struct node *head) {
    if(head == NULL || head->next == NULL) return head;
    return mergeChildSort(head, mergeSort(head->next));
}

main() {
    return 0;
}
