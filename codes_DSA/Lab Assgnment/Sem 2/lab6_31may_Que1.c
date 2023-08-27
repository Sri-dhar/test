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

void printBinTree2D(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 6;

    printBinTree2D(root->right, space);

    printf("\n");
    for (int i = 6; i < space; i++)
        printf(" ");

    if (root->left && root->right) {
        printf("%d\n", root->data);
        for (int i = 6; i < space; i++)
            printf(" ");
        //printf("/ ");
        for (int i = 8; i < space; i++)
            printf(" ");
        //printf("\\");
    } else if (root->right) {
        printf("%d\n", root->data);
        for (int i = 6; i < space; i++)
            printf(" ");
        //printf("/");

    } else if (root->left) {
        printf("%d\n", root->data);
        for (int i = 6; i < space; i++)
            printf(" ");
       // printf("\\");
    } else {
        printf("%d", root->data);
    }

    printBinTree2D(root->left, space);
}

int height(node root)
{
    if(root == NULL)
    return 0;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh > rh)
        return lh + 1;
        else
        return rh + 1;
        }
}

int main() 
{
    node tree = NULL;
    fill_tree(&tree);
    printf("The Binary tree horizontally is :\n");
    printBinTree2D(tree, 0);
    printf("\n\nThe height of the binary tree entered is %d\n\n",height(tree)-1);
    return 0;
}
