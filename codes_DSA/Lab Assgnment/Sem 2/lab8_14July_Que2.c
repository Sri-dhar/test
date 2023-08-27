#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

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

void printTree(struct TreeNode* root, struct Trunk* prev, bool isLeft) {
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

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* constructBinaryTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct TreeNode* root = createNode(arr[i]);
    root->left = constructBinaryTree(arr, n, 2 * i + 1);
    root->right = constructBinaryTree(arr, n, 2 * i + 2);

    return root;
}

void displayBinaryTree(struct TreeNode* root) {
    printf("Binary Tree:\n");
    printTree(root, NULL, false);
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void displayMaxHeap(int arr[], int n) {
    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    struct TreeNode* root = constructBinaryTree(arr, n, 0);
    displayBinaryTree(root);
}

void insertElement(int arr[], int* n, int element) {
    if (*n == MAX_SIZE) {
        printf("Heap is full. Cannot insert element.\n");
        return;
    }

    (*n)++;
    int i = *n - 1;
    arr[i] = element;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteElement(int arr[], int* n, int index) {
    if (*n <= index) {
        printf("Invalid index. Cannot delete element.\n");
        return;
    }

    arr[index] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, index);
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    printf("Enter elements to construct a max heap (enter -1 to stop):\n");
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        insertElement(arr, &n, num);
    }

    displayMaxHeap(arr, n);

    int element;
    printf("Enter an element you want to insert: ");
    scanf("%d", &element);
    insertElement(arr, &n, element);
    displayMaxHeap(arr, n);

    int index;
    printf("Enter the index you want to delete an element from: ");
    scanf("%d", &index);
    deleteElement(arr, &n, index);
    displayMaxHeap(arr, n);

    return 0;
}
