#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Trunk {
    struct Trunk* prev;
    char* str;
};

struct Node* newnode(int data) {
    struct Node* pnode = (struct Node*)malloc(sizeof(struct Node));
    pnode->data = data;
    pnode->left = pnode->right = NULL;
    return pnode;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

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

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* root = newnode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
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

void destroyTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

int main() {

    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
     int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    // Print the tree
    printTree(root, NULL, false);

    // Cleanup memory
    destroyTree(root);

    return 0;
}
