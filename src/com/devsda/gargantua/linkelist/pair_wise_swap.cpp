#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void add_node(struct node **head, int data) {
    struct node *newNode = new node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void display(struct node *head) {
    while(head != NULL) {
        cout << head->data << "   ";
        head = head->next;
    }
}

/*
void pair_wise(struct node **head, struct node **head_next) {
    cout << "bhr kb aaoge yhaa se\n";
    if(*head_next == NULL) return;
    if((*head_next)->next != NULL) pair_wise( &((*head_next)->next), &((*head_next)->next->next) );
    (*head)->next = (*head_next)->next;
    (*head_next)->next = *head;
    cout << endl; display(*head_next);
}*/

void pair_wise(struct node **head) {
    struct node *final_ptr = (*head)->next;
    struct node *current = (*head);
    struct node *current_next = (*head)->next;

    while(current_next->next != NULL) {
        cout << "\ndata  " << current->data << "  " << current_next->data;
        current->next = current_next->next;
        current_next->next = current;

        current = current->next;
        current_next = current->next;
        cout << endl; display(final_ptr);
    }
}



main() {
    int n;
    int x;

    cin >> n;

    struct node *head = NULL;
    for(int i = 0; i < n; i++) {
        cin >> x;
        add_node(&head, x);
    }

    cout << endl;
    display(head);
    cout << endl;

    pair_wise( &head );

    cout << endl;
    display(head);

    return 0;
}
