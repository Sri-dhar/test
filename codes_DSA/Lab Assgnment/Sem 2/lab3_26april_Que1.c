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

    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    if (length == 0) {
        return NULL;
    }
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
    printf("\n\nDo you want to add another element in front of the list\n(Enter 1 for yes and anything else for no)\n");
    int ip;
    scanf("%d",&ip);
    if(ip==1)
    {
    printf("\nEnter the element you want to add in front of the list : ");
    int elmt=0;
    scanf("%d",&elmt);
    addfirst(elmt,&List);
    printlist(List);
    }
    size = sizefinder(List);
    printf("\nsize:%d\n",size);
    node mid=getMiddleNode(List);
    if(size%2 == 1)
    {
        printf("Since the no. of elements in the list is odd\nWe are removing the %dth index whose value is %d",size/2,mid->data);
        remove_at_index(size/2,&List);
    }
    else
    {
        printf("\nSince the no. of elements in the list is even.\nThere are two middle elements\n");
        printf("\nIf you want to delete the middle left element Enter 1");
        printf("\nIf you want to delete the middle right element Enter 2");
        printf("\nIf you want to delete both the middle element Enter 3\n");
        int input=0; scanf("%d",&input);
        if(input == 1)
        {
            printf("Deleting the middle left element");
            remove_at_index(size/2 -1,&List);
        }
        else if(input ==2)
        {
            printf("Deleting the middle right element");
            remove_at_index(size/2,&List);
        }
        else if(input ==3)
        {
            printf("Deleting both the middle elements");
            remove_at_index(size/2,&List);
            size=sizefinder(List);
            remove_at_index(size/2,&List);
        }

    }
    printf("\n");
    printlist(List);
    return 0;
}
