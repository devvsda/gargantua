#include<iostream>

using namespace std;

bool isPairPresent(struct node *root, int target) {
    stack<struct node *> s1, s2;

    bool done1 = done2 = false;
    int val1, val2;
    struct node *current1 = root;
    struct node *current2 = root;

    while(1) {
        while(done == false) {
            if (current1 != NULL) {
                s1.push(current1);
                current1 = current1->left;
            }
            else {
                if(s1.isEmpty()) done = true;
                else {
                    current1 = s1.front();
                    s1.pop();
                    val1 = current1->data;
                    current1 = current1->right;
                    done = true;
                }
            }
        }

        while(done == false) {
            if(current2 != NULL) {
                s2.push(current2);
                current2 = current2->right;
            }
            else {
                if(s2.empty()) done = true;
                else {
                    current2 = s2.front();
                    s2.pop();
                    val2 =  current2->data;
                    current2 = current->left;
                    done = true;
                }
            }
        }

        if(val1 > val2) return false;
        if( (val1 != val2) &&  (val1 + val2) == target ) return true;
        if( (val1 != val2) && (val1 + val2) > target ) done2 = false;
        if( (val1 != val2) && (val1 + val2) < target ) done1 = false;
    }
}

main() {
    return 0;
}
