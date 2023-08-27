#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node *node;
typedef struct Node  Node;

struct Node{
    char data;
    node next;
};

node newNode(char data , node node_next)
{
    node addr = (node) calloc(1,sizeof(Node));
    addr->data=data;
    addr->next=node_next;
    return addr;
}

void push(char data, node* List)
{
    *List = newNode(data,*List);
}

int pop(node *List)
{
    if(List == NULL)
        return -1;
    node current = *List;
    *List = current->next;
    free(current);
    current = NULL;
    return 0;
}

char peek(node *List)
{
    return (*List)->data;
}

int main()
{
    printf("Enter the string whose parenthesis you want to check :\n");
    node stack = NULL;
    for(int i=0; i<50; i++) push('9',&stack);
    push('0',&stack);
    char* arr = (char*) calloc(100,sizeof(char));
    fgets(arr,100,stdin);
    int sizeofarr=strlen(arr)-1;
    for(int i=0; i<sizeofarr ; i++)
    {
        if(arr[i]=='{'||arr[i]=='('||arr[i]=='[')
            push('1',&stack);
        if(arr[i]=='}'||arr[i]==')'||arr[i]==']')
            {
                int a = pop(&stack);
                if(a == -1) { printf("Enter a valid string"); break; }
            }
    }
    free(arr);
    arr=NULL;
    if(peek(&stack)=='0'){
        printf("\nThe expression you entered has balanced parentheses\n");
    }
    else if(peek(&stack)=='1'){
        printf("\nThe expression you entered does not have balanced parentheses\n");
    }
    else if(peek(&stack)=='9'){
        printf("\nThe expression you entered is not valid\n");
    }

    return 0;

}
