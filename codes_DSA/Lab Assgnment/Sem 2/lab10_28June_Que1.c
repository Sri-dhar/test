#include <stdio.h>
#include <stdlib.h>

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

void fill_rightsubtree(node* root, int* size);
void fill_leftsubtree(node* root, int* size) {
    if (*root == NULL)
        return;
    printf("Enter the left element of %d\n", (*root)->data);
    int leftelmt;
    scanf("%d", &leftelmt);
    if (leftelmt != -1) {
        node leftnode = newnode(leftelmt);
        (*size)++;
        (*root)->left = leftnode;
        fill_leftsubtree(&((*root)->left), size);
        fill_rightsubtree(&((*root)->left), size);
    }
    else
        return;
}

void fill_rightsubtree(node* root, int* size) {
    if (*root == NULL)
        return;
    printf("Enter the right element of %d\n", (*root)->data);
    int rightelmt;
    scanf("%d", &rightelmt);
    if (rightelmt != -1) {
        node rightnode = newnode(rightelmt);
        (*size)++;
        (*root)->right = rightnode;
        fill_leftsubtree(&((*root)->right), size);
        fill_rightsubtree(&((*root)->right), size);
    }
    else
        return;
}

void fill_tree(node* root, int* size) {
    printf("Enter the root of the tree \n");
    int r_elmt;
    scanf("%d", &r_elmt);
    *root = newnode(r_elmt);
    (*size)++;
    fill_leftsubtree(root, size);
    fill_rightsubtree(root, size);
}

void inorder(node root, int* count_arr, int* counter) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, count_arr, counter);
    count_arr[*counter] = root->data;
    (*counter)++;
    inorder(root->right, count_arr, counter);
}

int main() {
    node root = NULL;
    int size = 0;
    fill_tree(&root, &size);
    int counter = 0;
    int* count_arr = (int*)calloc(size, sizeof(int));
    inorder(root, count_arr, &counter);
    int flag = 0;
    for (int i = 0; i < size - 1; i++) {
        if (i != 0 && i != size - 1) {
            if (!(count_arr[i] >= count_arr[i - 1] && count_arr[i] <= count_arr[i + 1]))
                flag = 1;
        }
    }
    if (flag)
        printf("\nThe tree is Not a BST");
    else
        printf("\nThe tree is a BST");
    return 0;
}
