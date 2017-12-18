#include<iostream>
#include<queue>

using namespace std;

int maxWidth(struct node *root) {
    if(root === NULL) return 0;
    queue<node *> q;
    q.push(root);
    int maxSize = 0;
    while(!q.empty()) {
        int currentSize = q.size();
        if(currentSize > maxSize) {
            maxSize = currentSize;
        }
        while(currentSize > 0) {
            struct node *temp = q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return maxSize;
}

main() {
    return 0;
}
