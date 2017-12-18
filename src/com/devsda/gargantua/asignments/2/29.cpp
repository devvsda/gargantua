#include<iostream>

using namespace std;

struct node *addSameLength(struct node *head1, struct node *head2, int *carry) {
    if(head1 == NULL) return NULL;
    struct node *result = (struct node *)malloc(sizeof(struct node));
    result->next = addSameLength(head1->next, head2->next, carry);
    int sum = head1->data + head2->data + *carry;
    result->data = sum % 10;
    *carry = sum/10;
    return result;
}

void addRemaining(struct node *head1, struct node *current, int *carry, struct node **result) {
    if(head1 == current) return;
    addRemaining(head1->next, current, carry, result);
    int sum = head1->data + *carrry;
    *carry = sum / 10;
    sum = sum%10;
    push(result,sum);
}

void addLists(struct node *head1, struct node *head2, struct node **result) {
    if(head1 == NULL) {
        *result = head2;
        return;
    }
    if(head2 == NULL) {
        *result = head1;
        return;
    }
    int size1 = getSize(head1);
    int size2 = getSize(head2);
    int diff = abs(size1 - size2);
    int carry = 0;

    if(size1 < size2) swap(&head1, &head2);
    struct node *current = head1;

    while(diff > 0) {
        current = current->next;
        diff--;
    }

    result = addSameLength(current, head2, &carry);
    if(diff != 0) addRemaining(head1, current, &carry, &result);
    if(carry) push(result, carry);
}

main() {
    return 0;
}
