#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

node newNode(int data, node node_next, node node_prev) {
    node addr = (node)calloc(1, sizeof(Node_t));
    addr->data = data;
    addr->next = node_next;
    addr->prev = node_prev;
    return addr;
}

void addfirst(node* List, int data) {
    *List = newNode(data, *List, NULL);
}

void addlast(node* List, int data) {
    if ((*List) == NULL) {
        addfirst(List, data);
        return;
    }

    node current = *List;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data, NULL, current);
}

void printlist(node List) {
    printf("\nNULL <=> ");
    node pnode = List;
    while (pnode != NULL) {
        printf("%d <=> ", pnode->data);
        pnode = pnode->next;
    }
    printf(" NULL");
}

node merge(node* List1, node* List2, node* merged)
{
    if (*List1 == NULL) { return *List2; }
    if (*List2 == NULL) { return *List1; }
    node L1 = *List1;
    node L2 = *List2;
    while(L1 != NULL && L2 != NULL )
    {
        if(L1->data <= L2->data)
        {
            addlast(merged, L1->data);
            L1 = L1->next;
        }
        else
        {
            addlast(merged, L2->data);
            L2 = L2->next;
        }
    }
    while(L1 != NULL)
    {
        addlast(merged, L1->data);
        L1 = L1->next;
    }
    while(L2 != NULL)
    {
        addlast(merged, L2->data);
        L2 = L2->next;
    }
    return *merged;
}

void sort(node* head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    int flag = 1;
    while (flag) {
        flag = 0;
        node current = *head;
        node prev = NULL;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                node temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev == NULL) {
                    *head = temp;
                } else {
                    prev->next = temp;
                }

                prev = temp;
                flag = 1;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

int main() {
    node List = NULL;
    printf("Enter the size of the first linked list you want to enter : ");
    int sizer = 0;
    scanf("%d", &sizer);
    printf("Enter the elements of the linked list :\n");
    for (int i = 0; i < sizer; i++) {
        int sdata = 0;
        scanf("%d", &sdata);
        addlast(&List, sdata);
    }
    printf("\n");
    printf("The first linked list is : ");
    printlist(List);
    printf("\n\n");

    node List2 = NULL;
    printf("Enter the size of the second linked list you want to enter : ");
    int sizer2 = 0;
    scanf("%d", &sizer2);
    printf("Enter the elements of the linked list :\n");
    for (int i = 0; i < sizer2; i++) {
        int sdata2 = 0;
        scanf("%d", &sdata2);
        addlast(&List2, sdata2);
    }

    printf("\n");
    printf("The second linked list is : ");
    printlist(List2);

    printf("\n\nThe merged linked list is : ");
    node sortedList = NULL;
    sortedList = merge(&List, &List2, &sortedList);  
    printlist(sortedList);   
    sort(&sortedList);
    printf("\n\nThe merged and sorted linked list is: ");
    printlist(sortedList);   
    return 0;
}
