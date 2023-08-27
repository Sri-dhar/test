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

void addfirst(int data, node* List)
{
    *List = newNode(data,*List);
}

void removefirst(node *List)
{
    node current = *List;
    *List = current->next;
    free(current);
    current = NULL; 

}

// void addlast(int data, node* List)
// {   
//     if(*List == NULL)
//     *List = newNode(data,*List);
//     else
//     {
//         while ((*List)->next != NULL)
//         {
//             *List = (*List)->next;
//         }
//     }
// }

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

void removeLast(node *List)
{
    if((*List) == NULL){
        printf("UNDERFLOW");
        return;
    } 
    node current = *List;
    while (current->next->next != NULL)
    {
        current = current ->next;
    }
    current->next = NULL;
    current=current->next;
    free(current);
}

void insert_at_idx(int data, int pos, node* List)
{   
    if(pos==1) {addfirst(data,List); return ;}
    pos--;
    node current = *List;
    while(pos--)
    {
        current = current->next;
        if(current == NULL)
        {   
            printf("Invalid position\n");
        }
    }
    node pnode = current->next;
    current->next = newNode(data,pnode);
    current->next->next = pnode;
    
}

void remove_at_index(int pos, node* List)
{   
    pos--;
    node  current = *List;
    while(pos--)
    {
        current = current -> next;
        if(current == NULL)
        {   
            printf("Invalid position\n");
            return;
        }
    }
    // node pnode = current -> next -> next;
   node pnode = current -> next;
    current->next=pnode->next;
    // current->next=pnode;
     free(pnode);
    pnode = NULL;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_linked_list(node *List)
{
    int swapped;
    node ptr1;
    node lptr = NULL;

    if (List == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = *List;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(&(ptr1->data), &(ptr1->next->data));
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


void printlist(node List)
{
    printf("\n");
    node pnode = List;
    while(pnode != NULL)
    {
        printf("%d->",pnode->data);
        printf(" Next (%d)\n", pnode->next);
        pnode = pnode->next;
    }
    printf(" NULL");
    
}

// void swapforsort()

// void sort_linked_list(node *List)
// {   
//     int count=0;
//     node* counter = List;
//     while(counter != NULL)
//     {
//        count++;
//        counter = counter -> next; 
//     }
//     for(int i=0;i<count;i++)
//     {
//         for(int j=0;j<count-1;j++)
//         {
//             int *a = &((*List)->data);
//             int *b = &((*List)->data);
//             while(i--) a = &(a->next->data);
//             while(j--) b = &(b->next->data);
//             int temp = *a;
//             *a = *b;
//             *b = temp;
//         }
//     }
// }





int main()
{
    node List = NULL;
    List = newNode(1,NULL); 
    addfirst(2,&List);
    addlast (3,&List);
    addfirst(4,&List);
    addfirst(5,&List);
    insert_at_idx(67,2,&List);
    printlist(List);
    printf("\n");
    remove_at_index(3,&List);
    printlist(List);
    printf("\n\nHello");
    // removefirst(&List);
    // printlist(List); 
    return 0;
}
