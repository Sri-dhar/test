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

int isEqual(node* Queue1 , node *Queue2)
{
    node pnode1 = *Queue1;
    node pnode2 = *Queue2;

    while(pnode1 != NULL && pnode2 != NULL) {
        if(pnode1->data != pnode2->data) {
            return 0;
        }
        pnode1 = pnode1->next;
        pnode2 = pnode2->next;
    }

    if(pnode1 == NULL && pnode2 == NULL) {
        return 1;
    }

    return 0;
}


int main()
{
    printf("THE FOLLOWING OPERATION ARE GOING TO HAPPEN ON FIRST QUEUE\n");
    node Queue1 = NULL;
    int exit=0;
    int ip=0;
    while(exit==0)
    {

        printf("\nEnter the element you want to add in the Queue1 : ");
        scanf("%d",&ip);
        enqueue(ip,&Queue1);
        printlist(Queue1);
        printf("\n");
        fflush(stdin);
        printf("\nEnter 'e' if you want to exit or \nEnter 'd' to dequeue \nEnter 'c' to continue:\n");
        char option;
        scanf(" %c",&option);
        if(option =='e') { printf("The final Queue1 is ");  printlist(Queue1);printf("\n");printf("\n"); break ;}
        if(option =='d') {  dequeue(&Queue1);
                            if(Queue1 == NULL) {printf("The Queue1 is empty\n");}
                            else {printf("The Queue1 after popping is :\n\n ");}
                            printlist(Queue1);
                            }
        if(option =='c') continue;
        fflush(stdin);
    }

    printf("THE FOLLOWING OPERATION ARE GOING TO HAPPEN ON SECOND QUEUE\n");
    fflush(stdin);
    node Queue2 = NULL;
    int exit2=0;
    int ip2=0;
    while(exit2==0)
    {

        printf("\nEnter the element you want to add in the Queue2 : ");
        scanf("%d",&ip2);
        enqueue(ip2,&Queue2);
        printlist(Queue2);
        printf("\n");
        fflush(stdin);
        printf("\nEnter 'e' if you want to exit or \nEnter 'd' to dequeue \nEnter 'c' to continue:\n");
        char option2;
        scanf("%c",&option2);
        if(option2 =='e') { printf("The final Queue2 is ");  printlist(Queue2);printf("\n");printf("\n"); break ;}
        if(option2 =='d') {  dequeue(&Queue2);
                            if(Queue2 == NULL) {printf("The Queue2 is empty\n");}
                            else {printf("The Queue2 after popping is :\n\n ");}
                            printlist(Queue2);
                            }
        if(option2 =='c') continue;
        fflush(stdin);
    }

    printf("\nThe first queue is : ");printlist(Queue1);
    printf("\n");
    printf("\nThe second queue is : ");printlist(Queue2);
    printf("\n\n\n");
    isEqual(&Queue1,&Queue2)==0?printf("The Queues are not equal\n"):printf("The Queues are equal\n");


    return 0;
}
