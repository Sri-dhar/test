#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;

struct Node {
    int data;
    node left;
    node right;
};

node newnode(int data) {
    node pnode = (node)malloc(sizeof(Node_t));
    pnode->data = data;
    pnode->left = pnode->right = NULL;
    return pnode;
}

void fill_rightsubtree(node* root);
void fill_leftsubtree(node* root) {
    if (*root == NULL) return;
    printf("Enter the left element of %d\n", (*root)->data);
    int leftelmt;
    scanf("%d", &leftelmt);
    if (leftelmt != -1) {
        node leftnode = newnode(leftelmt);
        (*root)->left = leftnode;
        fill_leftsubtree(&((*root)->left));
        fill_rightsubtree(&((*root)->left));
    }
    else return;
}

void fill_rightsubtree(node* root) {
    if (*root == NULL) return;
    printf("Enter the right element of %d\n", (*root)->data);
    int rightelmt;
    scanf("%d", &rightelmt);
    if (rightelmt != -1) {
        node rightnode = newnode(rightelmt);
        (*root)->right = rightnode;
        fill_leftsubtree(&((*root)->right));
        fill_rightsubtree(&((*root)->right));
    }
    else return;
}

void fill_tree(node* root) {
    printf("Enter the root of the tree \n");
    int r_elmt;
    scanf("%d", &r_elmt);
    *root = newnode(r_elmt);
    fill_leftsubtree(root);
    fill_rightsubtree(root);
}

void Rinorder(node root) {
    if (root == NULL) return;
    Rinorder(root->left);
    printf("%d ", root->data);
    Rinorder(root->right);
}

void Rpreorder(node root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    Rpreorder(root->left);
    Rpreorder(root->right);
}

void Rpostorder(node root) {
    if (root == NULL) return;
    Rpostorder(root->left);
    Rpostorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node tree = NULL;
    fill_tree(&tree);
    printf("Recursive Inorder traversal: ");
    Rinorder(tree);
    printf("\n");

    printf("Recursive Preorder traversal: ");
    Rpreorder(tree);
    printf("\n");

    printf("Recursive Postorder traversal: ");
    Rpostorder(tree);
    printf("\n");
    return 0;
}