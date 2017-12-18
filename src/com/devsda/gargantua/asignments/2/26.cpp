#include<iostream>

using namespace std;

bool hasSum(struct node *root, int sum) {
    if(root == NULL){
        return (sum == 0);
    }
    else {
        int subSum = sum - subSum;
        bool res = 0;
        if(subSum == 0 && root->left == NULL && root->right == NULL) {
            return 1;
        }

        if(root->left) {
            res = res || hasSum(root->left, subSum);
        }
        if(root->right) {
            res = res || hasSum(root->right, subSum);
        }
        return res;
}
main() {
    return 0;
}
