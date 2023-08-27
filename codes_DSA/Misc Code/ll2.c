#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node_t, *node;

node newNode(int data, node next)
{
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

node addAtIndex(int data, int index, node head) {
    if (index == 0) {
        // Inserting at the start of the list.
        return newNode(data, head);
    }
    int i = 0;
    node current = head;
    while (i < index - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        // Index out of bounds.
        return head;
    }
    // Inserting at the desired index.
    node new_node = newNode(data, current->next);
    current->next = new_node;
    return head;
}
void remove_first(node *head) {
    if (*head == NULL) {
        return;
    }
    node temp = *head;
    *head = temp->next;
    free(temp);
}


void printlist(node node)
{
    while(node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
}

int main()
{
    node list = newNode(89, NULL);
    list = addfirst(234,list);
    list = addfirst(345,list);
    remove_first(&list);
    list = addfirst(894,list);
    
    printlist(list);
    
    // Freeing dynamically allocated memory
    node temp = list;
    while(temp!= NULL)
    {
        node current = temp;
        temp = temp-> next;
        free(current);
    }
    
    return 0;
}
