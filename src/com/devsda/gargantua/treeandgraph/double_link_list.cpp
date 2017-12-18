#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *previous;
};

struct node *create_new_node(int value) {
    struct node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

struct node *insert_node(struct node *(&head), struct node *(&tail), int value) {
    struct node *new_node = create_new_node(value);
    //cout << "bhai create sahi h\n";
    if(head == NULL) {
        new_node->next = new_node;
        new_node->previous = new_node;
        head = new_node;
        tail = new_node;
    }
    else {
       new_node->next = head;
        head->previous = new_node;
        tail->next = new_node;
        new_node->previous = tail;
        head = new_node;
    }
    return head;
}


void display(struct node *head, struct node *tail) {
    struct node *head_temp = head;
    if(head_temp != NULL) {
        cout << head_temp->data << endl;
        head_temp = head_temp->next;
    }
    while(head_temp != head) {
        cout << head_temp->data << endl;
        head_temp = head_temp->next;
    }
}

main() {
    int n;
    int x;
    struct node *head = NULL;
    struct node *tail = NULL;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        //cout << "sahi h bidu " << i+1 << endl;
        head = insert_node(head, tail, x);
    }
    display(head, tail);
    return 0;
}

