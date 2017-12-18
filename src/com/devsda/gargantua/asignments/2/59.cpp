

void insertNewNode(TriNode **root, string word, int i, int index) {
    if(*root == NULL) *root = newNode();

    if(i < word.size()) insertNewNode(root->child[word[i] - 'a', index);
    else {
        if(root->end != 1) {
            root->end = 1;
            root->head = newNode(index);
        }
        else  {
            struct node *current = root->head;
            while(current->next != NULL)  current = current->next;
            current->next = newNode(index);
        }
    }

}
