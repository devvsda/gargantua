#include<iostream>

using namespace std;

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

char inorder[100];
char preorder[100];

int search(char val, int start, int size) {
    for(int i = start; i <= size; i++) {
        if(inorder[i] == val) { cout << i << endl; return i; }
    }
}

struct node *buildTree(int i, int size) {
    static int index_preorder = 0;
    if(i > size) return NULL;
    struct node *root = newNode(preorder[index_preorder]);
    //cout << preorder[index_preorder] << endl;
    int index = search(preorder[index_preorder++], i, size);
    //cout << index << endl;
    root->left = buildTree(i, index - 1);
    root->right = buildTree(index+1, size);
    return root;
}

void printInorder(struct node* node)
{
  if (node == NULL) return;
  printInorder(node->left);
  printf("%c ", node->data);
  printInorder(node->right);
}

main() {
    freopen("input.txt", "r", stdin);

    int n;
    struct node *head = NULL;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    head = buildTree(0, n-1);

    printInorder(head);

    return 0;
}
