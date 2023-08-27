#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;

struct Node{
    int data;
    struct Node * next;
};

node newNode(int data , node node_next)
{
    node addr = (node) calloc(1,sizeof(Node_t));
    addr->data=data;
    addr->next=node_next;
    return addr;
}

void enqueue(int data, node* Queue)
{
    *Queue = newNode(data,*Queue);
}

void dequeue(node *Queue)
{
    if((*Queue) == NULL){
        printf("UNDERFLOW");
        return;
    }
    node current = *Queue;
    while (current->next->next != NULL)
    {
        current = current ->next;
    }
    current->next = NULL;
    current=current->next;
    free(current);
}


void printlist(node Queue)
{
    printf("\n");
    node pnode = Queue;
    while(pnode != NULL)
    {
        printf("%d -> ",pnode->data);
        pnode = pnode->next;
    }
    printf(" FRONT ");

}
int main()
{
    node Queue = NULL;
    int exit=0;
    int ip=0;
    while(exit==0)
    {
        printf("\nEnter the element you want to add in the queue : ");
        scanf("%d",&ip);
        enqueue(ip,&Queue);
        printlist(Queue);
        printf("\n");
        fflush(stdin);
        printf("\nEnter 'e' if you want to exit or \nEnter 'd' to dequeue \nEnter 'c' to continue:\n");
        char option;
        scanf("%c",&option);
        if(option =='e') { printf("The final queue is ");  printlist(Queue);printf("\n");printf("\n"); break ;}
        if(option =='d') {  dequeue(&Queue);
                            if(Queue == NULL) {printf("The Queue is empty\n");}
                            else {printf("The queue after popping is :\n\n ");}
                            printlist(Queue);
                            }
        if(option =='c') continue;
        fflush(stdin);
    }
    return 0;
}
