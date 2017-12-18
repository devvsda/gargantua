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

bool palindrome(struct node** left, struct node *right) {
    if(right == NULL) return 1;
    bool isp = palindrome(left, right->next);
    if(isp == 0) return 0;
    bool isp1 = ( (right->data) == (*left)->data );
    (*left) = (*left)->next;
    return isp1;

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

    cout << endl << palindrome(&head, head);

    //cout << endl << "after    ";
    //display(head);

    return 0;
}
