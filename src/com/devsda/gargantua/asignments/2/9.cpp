#include<iostream>

using namespace std;

int heightI(struct node *root) {
    if(root == NULL) return 0;
    queue<node*> q;

    q.push(root);
    int nodeCount = 0;
    int height = 0;
    while(1) {

        nodeCount = q.size();
        if(nodeCount == 0) return height;
        height++;
        while(nodeCount > 0) {
            struct node *n = q.pop();
            if(n->left != NULL) q.push(n->left);
            if(n->right != NULL) q.push(n->right);
            nodeCount--;
        }
    }
}

main() {
    return 0;
}
