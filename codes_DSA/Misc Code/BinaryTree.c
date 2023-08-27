#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;
//
typedef struct QueueNode QueueNode_t;
typedef struct QueueNode* queueNode;
//

//Queue stuff
struct QueueNode {
    node data;
    queueNode next;
};

queueNode newQueueNode(node data) {
    queueNode qNode = (queueNode)malloc(sizeof(QueueNode_t));
    qNode->data = data;
    qNode->next = NULL;
    return qNode;
}

void enqueue(queueNode* front, queueNode* rear, node data) {
    queueNode qNode = newQueueNode(data);
    if (*rear == NULL) {
        *front = *rear = qNode;
    } else {
        (*rear)->next = qNode;
        *rear = qNode;
    }
}

node dequeue(queueNode* front, queueNode* rear) {
    if (*front == NULL)
        return NULL;

    queueNode temp = *front;
    node data = temp->data;

    if (*front == *rear)
        *rear = NULL;
    *front = (*front)->next;

    free(temp);
    return data;
}

int isQueueEmpty(queueNode front) {
    return (front == NULL);
}
//Queue stuff ends here


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

void insertBinaryTree(node* root, int data) {
    if (*root == NULL) {
        *root = newnode(data);
        return;
    }

    queueNode front = NULL;
    queueNode rear = NULL;
    enqueue(&front, &rear, *root);

    while (!isQueueEmpty(front)) {
        node current = dequeue(&front, &rear);

        if (current->left == NULL) {
            current->left = newnode(data);
            return;
        } else {
            enqueue(&front, &rear, current->left);
        }

        if (current->right == NULL) {
            current->right = newnode(data);
            return;
        } else {
            enqueue(&front, &rear, current->right);
        }
    }
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

void Iter_inorder(node root) {
    if (root == NULL) return;
    node stack[100];
    int top = -1;

    while (1) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }

        if (top == -1) break;

        root = stack[top--];
        printf("%d ", root->data);

        root = root->right;
    }
}

void Iter_preorder(node root) {
    if (root == NULL) return;
    node stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        root = stack[top--];
        printf("%d ", root->data);
        if (root->right)
            stack[++top] = root->right;
        if (root->left)
            stack[++top] = root->left;
    }
}

void Iter_postorder(node root) {
    if (root == NULL) return;
    node stack[100];
    int top = -1;
    node last_visited = NULL;

    while (root || top >= 0) {
        if (root) {
            stack[++top] = root;
            root = root->left;
        }
        else {
            node peek_node = stack[top];
            if (peek_node->right && last_visited != peek_node->right) {
                root = peek_node->right;
            }
            else {
                printf("%d ", peek_node->data);
                last_visited = peek_node;
                --top;
            }
        }
    }
}

void level_order_traversal(node root) {
    if (root == NULL)
        return;

    queueNode front2 = NULL;
    queueNode rear2 = NULL;

    enqueue(&front2, &rear2, root);

    while (!isQueueEmpty(front2)) {
        node current = dequeue(&front2, &rear2);
        printf("%d ", current->data);

        if (current->left)
            enqueue(&front2, &rear2, current->left);
        if (current->right)
            enqueue(&front2, &rear2, current->right);
    }
}


void fill_BST(node* root) {
    printf("Enter the root of the tree \n");
    int r_elmt;
    scanf("%d", &r_elmt);
    *root = newnode(r_elmt);

    while (1) {
        int elmt;
        printf("Enter an element (-1 to stop): ");
        scanf("%d", &elmt);
        if (elmt == -1)
            break;
        
        node current = *root;
        node parent = NULL;
//position
        while (current != NULL) {
            if (elmt == current->data) {
                printf("Duplicate element not allowed. Please enter a different element.\n");
                break;
            }
            parent = current;
            if (elmt < current->data)
                current = current->left;
            else
                current = current->right;
        }
//insertion
        if (current == NULL) {
            if (elmt < parent->data)
                parent->left = newnode(elmt);
            else
                parent->right = newnode(elmt);
        }
    }
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

//printing binary tree horizontally in branching manner
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

node searchBST(node root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

node findMinValueNode(node root) {
    node current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

node deleteBST(node root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {

        // Case 1: No child or one child
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        node minValueNode = findMinValueNode(root->right);
        root->data = minValueNode->data;
        root->right = deleteBST(root->right, minValueNode->data);
    }
    return root;
}

int main() {
    node tree = NULL;
    fill_BST(&tree);
    printf("Level Order traversal: ");
    level_order_traversal(tree);
    printf("\n");

    printf("Recursive Inorder traversal: ");
    Rinorder(tree);
    printf("\n");

    printf("Recursive Preorder traversal: ");
    Rpreorder(tree);
    printf("\n");

    printf("Recursive Postorder traversal: ");
    Rpostorder(tree);
    printf("\n");

    printf("Iterative Inorder traversal: ");
    Iter_inorder(tree);
    printf("\n");

    printf("Iterative Preorder traversal: ");
    Iter_preorder(tree);
    printf("\n");

    printf("Iterative Postorder traversal: ");
    Iter_postorder(tree);
    printf("\n");

    printf("Binary Tree:\n");
    printBinTree2D(tree, 0);
    printf("\n");

    printf("\n\nThe height of the binary tree entered is %d\n\n",height(tree));

    return 0;
}

void destroyTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}