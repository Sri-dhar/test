#include <stdio.h>
#include <stdlib.h>

typedef struct Node* node;
typedef struct Node node_t;

struct Node {
    node left;
    node right;
    int data;
};

node root = NULL;

void insert(int key)
{
    node t = root;
    node r = NULL;
    node p = NULL;

    if (t == NULL) {
        p = (node)malloc(sizeof(node_t));
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->left;
        }
        else if (key > t->data) {
            t = t->right;
        }
        else {
            return;
        }
    }

    p = (node)malloc(sizeof(node_t));
    p->data = key;
    p->left = p->right = NULL;
    if (key < r->data) {
        r->left = p;
    }
    else {
        r->right = p;
    }
}

void printBinaryTree(node root)
{
    if (root == NULL) {
        return;
    }

    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
}

int main(){
    insert(34);
    insert(56);
    insert(23);
    insert(12);
    insert(39);
    insert(90);
    insert(1);
    insert(456);
    printBinaryTree(root);
    return 0;
}