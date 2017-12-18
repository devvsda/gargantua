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

void RecursiveReverse(struct node** headRef) {
    struct node* first;
    struct node* rest;

    if (*headRef == NULL) return; // empty list base case

    first = *headRef; // suppose first = {1, 2, 3}
    rest = first->next; // rest = {2, 3}

    if (rest == NULL) return; // empty rest base case

    RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
// after: rest = {3, 2}
    cout << endl << "bhead\n";
    display(*headRef);
    cout << endl << "brest\n";
    display(rest);
    cout << endl;
    first->next->next = first; // put the first elem on the end of the list
    first->next = NULL; // (tricky step -- make a drawing)
    *headRef = rest; // fix the head pointer
    cout << endl << "ahead\n";
    display(*headRef);
    cout << endl << "arest\n";
    display(rest);
    cout << endl;
}


main() {
    int n;
    int x;
    struct node *head = NULL;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        add_node(&head, x);
    }
    cout << endl << "before   ";
    display(head);

    RecursiveReverse(&head);

    cout << endl << "after    ";
    display(head);

    return 0;
}
