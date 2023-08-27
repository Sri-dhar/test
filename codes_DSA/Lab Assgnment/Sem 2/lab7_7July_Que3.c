#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node_t, *node;

node newNode(int data, node next) {
    node new_node = (node) malloc(sizeof(Node_t));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

node addfirst(int data , node pnode)
{
    node new_head = newNode(data, pnode );
    return new_head;
}

node merge(node left, node right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    
    node result;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    
    return result;
}

void split(node head, node* left, node* right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }
    
    node slow = head;
    node fast = head->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(node* head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    node left, right;
    split(*head, &left, &right);
    
    mergeSort(&left);
    mergeSort(&right);
    
    *head = merge(left, right);
}

void printList(node node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    node list = NULL;
    printf("Enter the elements you want to enter in the list : \n");
    printf("Enter -1 to stop entering elements \n");
    int input=0;
    while (input != -1) {
        scanf("%d", &input);
        if (input != -1) {
            list = addfirst(input, list);
        }
    }
    
    printf("Original List: ");
    printList(list);
    printf("\n");
    
    mergeSort(&list);
    
    printf("Sorted List: ");
    printList(list);
    printf("\n");
    
    node temp = list;
    while (temp != NULL) {
        node current = temp;
        temp = temp->next;
        free(current);
    }
    
    return 0;
}
