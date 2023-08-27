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

void addlast(int data, node* List )
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

void printlist(node noide)
{
    while(noide != NULL)
    {
        printf("%d -> ", noide->data);
        noide = noide->next;
    }
    printf("NULL");
}


int isPalindrome(node List, int len)
{
        if (len <= 1)
    {
        return 1;
    }
    int mid = len / 2;
    node cur = List;
    node prev = NULL, next = NULL;
    for (int i = 0; i < mid; i++)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    if (len % 2 == 1)
    {
        cur = cur->next;
    }
    while (cur != NULL && prev != NULL)
    {
        if (cur->data != prev->data)
        {
            return 0;
        }
        cur = cur->next;
        prev = prev->next;
    }
    return 1;
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

    isPalindrome(List,size)?printf("\nThis List is a palindrome\n"):printf("\nThis list is not a palindrome\n");

    return 0;
}
