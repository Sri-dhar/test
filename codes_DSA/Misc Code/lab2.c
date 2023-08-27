#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;

struct Node {
    int data;
    struct Node* next;
};

node newNode(int data, node node_next)
{
    node addr = (node)calloc(1, sizeof(Node_t));
    addr->data = data;
    addr->next = node_next;
    return addr;
}

node addfirst(int data, node* List)
{
    *List = newNode(data, *List);
    return *List;
}

void addlast(int data, node *List)
{
    if((*List) == NULL){
        *List = newNode(data, NULL);
        return;
    }

    node current = *List;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode(data, NULL);
}

void remove_at_index(int pos, node* List)
{
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }

    pos--;
    node current = *List;
    while(pos--)
    {
        current = current->next;
        if (current == NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }

    node pnode = current->next;

    if (pnode == NULL) {
        printf("Invalid position\n");
        return;
    }
    current->next = pnode->next;
    free(pnode);
}

void printlist(node noide)
{
    while(noide != NULL)
    {
        printf("%d -> ", noide->data);
        noide = noide->next;
    }
    printf("NULL");
}

int sizefinder(node List)
{   int size=0;
    while(List!=NULL)
    {
        List = List->next;
        size++;
    }
    return size;
}
node getMiddleNode(node List){
    int length = 0;
    node temp = List;

    // counting the number of nodes in the given linked list.
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    if (length == 0) {
        return NULL; // no element present in the Linked List
    }

   // setting pointers to start from the nth position to find the middle value
    int pos = length/2;
    temp = List;
    node middleNode = temp;
    while(pos--)
    {
        middleNode = temp;
        temp = temp->next;
    }
if(length%2 == 1) return middleNode->next;
    return middleNode;
}

int main()
{
    node List = NULL;
    printf("Enter the no. of elements you want to enter in the linked list : ");
    int size;
    scanf("%d", &size);
    printf("Enter the elements you want to add\n");
    for (int i = 0; i < size; i++)
    {
        int dataa;
        scanf("%d", &dataa);
        addlast(dataa, &List);
    }
    printf("The list you entered is:\n");
    printlist(List);
    
    printf("\n");
    printlist(List);
    return 0;
}
