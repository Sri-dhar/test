#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node, *node;

node newNode(int data, node next)
{
    Node new = (Node) malloc(sizeof(Node));
    new->data = data;
    new->next = next;
    return new;
}

void printlist(node noide)
{
    while(noide!= NULL)
    {
        printf("%d",noide->data);
        noide = noide-> next;
    }
}
int main()
{
    int *list=newNode(89, NULL);
    
    printlist(list);

}