#include<iostream>

using namespace std;

bool deleteHelper(trie_node_t *pNode, char key[], int level, int len) {
    if(pNode == NULL) return false;
    if(level == len) {
        if(pNode->value) {
            pNode->value = 0;
            if(isItFree(pNode)) return true;
            return false;
        }
    }
    else {
        int index = key[level];
        if( deleteHelper(pNode->children[index], key, level + 1, len)) {
            free(pNode->children[index]);
            return ( isItFree(pNode) && !leafNode(pNode) );
        }
    }
    return false;
}
main() {
    return 0;
}
