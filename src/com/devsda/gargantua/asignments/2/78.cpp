#include<iostream>
#include<queue>

using namespace std;

int nextNode(struct node *root, int value) {
    queue<struct node*> q;
    q.push(root);

    while( !q.empty() ) {
        int sze = q.size();
        while(sze > 1) {
            struct node *temp = q.front();
            q.pop();
            if(temp->data == value) return (q.top()->data);
            q.push(temp->left);
            q.push(temp->right);
        }
        if( (sze == 1) && ( (q.top()->data) == value ) ) return -1;
        else q.pop();
    }
}

main() {
    return 0;
}
