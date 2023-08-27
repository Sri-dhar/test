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

int main()
{
    node root1 = NULL;
    node root2 = NULL;
    int count = 0;
    printf("Enter the first BST (Enter -1 to stop) : \n");
    while(1)
    {
        int input=0;
        scanf("%d",&input);
        if(input == -1)
        break;
        else{
            root1 = insertBST(root1, input);
            count++;
        }
    }
    printf("\nEnter the second BST (Enter -1 to stop) : \n");
    while(1)
    {
        int input=0;
        scanf("%d",&input);
        if(input == -1)
        break;
        else{
            root2 = insertBST(root2, input);
        }
    } 
    int* count_arr = (int*)calloc(count, sizeof(int));
    int* count_arr2 = (int*)calloc(count, sizeof(int));
    int counter = 0;
    int counter2 = 0;
    inorder(root1, count_arr, &counter);
    inorder(root2, count_arr2, &counter2);
    int flag=0;
    for(int i=0 ;i<counter;++i)
    {
        if(count_arr[i]!=count_arr2[i]) flag=1;
    }
    if(flag==1)
    printf("Not Equal");
    else
    printf("Equal");
    return 0;

}
