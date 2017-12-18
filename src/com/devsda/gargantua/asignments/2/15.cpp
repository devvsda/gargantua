#include<iostream>

using namespace std;

struct node* constructTree ( int pre[], int size ){
    if(size == 0) return NULL;
    struct node *root = newNode(pre[0]);
    stack<node *> s;
    s.push(root);

    for(int i = 1; i < size; i++) {
        if(pre[i] < s.front()->data) {
            s.front()->left = newNode(pre[i]);
            s.push(s.front()->left);
        }
        else {
            while( ( !s.empty() ) && ( pre[i] > s.front()->data ) ) {
                temp = s.pop();
            }

            if(temp != NULL) {
                temp->right = newNode(pre[i]);
                s.push(temp->right);
            }
        }
    }
    return root;
}
