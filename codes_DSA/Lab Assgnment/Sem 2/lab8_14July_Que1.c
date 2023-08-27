#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    pnode->left = NULL;
    pnode->right = NULL;
    return pnode;
}

struct Trunk {

    struct Trunk* prev;
    char* str;
};

struct Trunk* createTrunk(struct Trunk* prev, const char* str) {
    struct Trunk* trunk = (struct Trunk*)malloc(sizeof(struct Trunk));
    trunk->prev = prev;
    trunk->str = strdup(str);
    return trunk;
}

void showTrunks(struct Trunk* p) {
    if (p == NULL) {
        return;
    }

    showTrunks(p->prev);
    printf("%s", p->str);
}

void printTree(struct Node* root, struct Trunk* prev, bool isLeft) {
    if (root == NULL) {
        return;
    }

    const char* prev_str = "    ";
    struct Trunk* trunk = createTrunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev) {
        trunk->str = "|--";
    }
    else if (isLeft) {
        trunk->str = "|--";
        prev_str = "   |";
    }
    else {
        trunk->str = "`--";
        prev->str = strdup(prev_str);
    }

    showTrunks(trunk);
    printf("%d\n", root->data);

    if (prev) {
        prev->str = strdup(prev_str);
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

node insertBST(node root, int data) {
    if (root == NULL) {
        return newnode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }

    return root;
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

void preorder(node root, int* inorder, int* i)
{
    if (!root)
        return;
    root->data = inorder[(*i)++];
    preorder(root->left, inorder, i);
    preorder(root->right, inorder, i);
}

void BSTtoMinHeap(node root, int* inorder)
{
    int i = 0;
    preorder(root, inorder, &i);
}

void printHeap(int* heap, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void buildHeap(node root, int* heap, int* index) {
    if (root == NULL) {
        return;
    }

    heap[*index] = root->data;
    (*index)++;
    buildHeap(root->left, heap, index);
    buildHeap(root->right, heap, index);
}

int main() {
    node root = NULL;
    printf("Enter the array: ");
    printf("\nEnter -1 to stop\n");
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n != -1) {
        root = insertBST(root, n);
        scanf("%d", &n);
        count++;
    }

    printf("The Binary Search Tree is:\n\n");
    printTree(root, NULL, false);
    printf("\n\n");

    int* count_arr = (int*)calloc(count, sizeof(int));
    int counter = 0;
    inorder(root, count_arr, &counter);
    // count_arr now contains inorder of the BST

    BSTtoMinHeap(root, count_arr);

    int* heap = (int*)calloc(count, sizeof(int));
    int index = 0;
    buildHeap(root, heap, &index);
    printf("\n\nThe min heap is :\n\n");
    printTree(root, NULL, false);
    free(count_arr);
    free(heap);

    return 0;
}

