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

void printlist(node noide)
{
    while(noide != NULL)
    {
        printf("%d -> ", noide->data);
        noide = noide->next;
    }
    printf("NULL");
}

void remove_duplicates(node List) {
    node p1, p2, duplicate;
    p1 = List;

    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;

        while (p2->next != NULL)
        {
            if (p1->data == p2->next->data)
            {
                duplicate = p2->next;
                p2->next = p2->next->next;
                free(duplicate);
            }
            else
            {
                p2 = p2->next;
            }
        }

        p1 = p1->next;
    }
}

void intersection(node List1, node List2 , node *List_ixt)
{
    remove_duplicates(List1);
    remove_duplicates(List2);
    node p1 = List1;
    while (p1 != NULL) {
        node p2 = List2;
        while (p2 != NULL) {
            if (p1->data == p2->data) 
            {
                addfirst(p2->data, List_ixt);
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main()
{
    node List_intersection=NULL;
    node List = NULL;
    printf("Enter the no. of elements you want to enter in the 1st linked list : ");
    int size;
    scanf("%d", &size);
    printf("Enter the elements you want to add :\n");
    for (int i = 0; i < size; i++)
    {
        int dataa;
        scanf("%d", &dataa);
        addfirst(dataa, &List);
    }
    printf("The 1st list you entered is:\n");
    printlist(List);
    printf("\n\n");
    
    node List2 = NULL;
    printf("Enter the no. of elements you want to enter in the 2st linked list : ");
    int size2=0;
    scanf("%d", &size2);
    printf("Enter the elements you want to add :\n");
    for (int i = 0; i < size2; i++)
    {
        int dataa;
        scanf("%d", &dataa);
        addfirst(dataa, &List2);
    }
    printf("\nThe 2nd list you entered is:\n");
    printlist(List2);
    intersection(List, List2, &List_intersection);
    printf("\nIntersection of the 2 lists is:\n");
    printlist(List_intersection);
    return 0;
}

