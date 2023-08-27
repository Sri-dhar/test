#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to search for a value in an array
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to construct the tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    // Base case
    if (inStart > inEnd)
        return NULL;

    // Create a new node with the last element of postorder array
    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    // If the current node has no children, return it
    if (inStart == inEnd)
        return node;

    // Find the index of the current node in inorder array
    int inIndex = search(inorder, inStart, inEnd, node->data);

    // Construct the right subtree
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);

    // Construct the left subtree
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to print the inorder traversal of a binary tree
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Driver code
int main() {
    int inorder[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int postorder[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);

    return 0;
}
