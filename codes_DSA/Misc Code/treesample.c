#include <stdio.h>
#include <stdlib.h>

typedef struct Node* node;
typedef struct Node Node_t;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}



void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
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
        printf("\\");
    } else {
        printf("%d", root->data);
    }

    printBinTree2D(root->left, space);
}

int main() {
    int inorder[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int postorder[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printBinTree2D(root,0);
    return 0;
}
