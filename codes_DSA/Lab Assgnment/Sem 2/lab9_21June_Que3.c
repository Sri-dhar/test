#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node_t;
typedef struct Node* node;

struct Node {
    int data;
    struct Node* next;
};

node newNode(int data, node node_next) {
    node addr = (node)calloc(1, sizeof(Node_t));
    addr->data = data;
    addr->next = node_next;
    return addr;
}

void addfirst(int data, node* List) {
    *List = newNode(data, *List);
}

void removefirst(node* List) {
    node current = *List;
    *List = current->next;
    free(current);
    current = NULL;
}

void addlast(int data, node* List) {
    if ((*List) == NULL) {
        *List = newNode(data, NULL);
        return;
    }

    node current = *List;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data, NULL);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_linked_list(node* List) {
    int swapped;
    node ptr1;
    node lptr = NULL;

    if (List == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *List;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
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
        pnode = pnode->next;
    }
    printf(" NULL");
}

int function(node List, int size, int threshold) {
    int count = 0;
    node pnode = List;
    printf("\n");
    sort_linked_list(&List);
    printf("\n");
    printf("The list after %dth iteration is: ", count);
    printlist(List);
    printf("\n");
    printf("\n");
    if (pnode == NULL || pnode->next == NULL)
        return 0;

    if (pnode->data >= threshold)
        return -1;

    while (1) {
        if (pnode->data >= threshold)
            return count;

        int x = pnode->data + 2 * pnode->next->data;
        addlast(x, &List);
        removefirst(&List);
        removefirst(&List);
        sort_linked_list(&List);
        pnode = List;
        count++;
        printf("The list after %dth iteration is: ", count);
        printlist(List);
        printf("\n\n");
    }
}

int main() {
    node List = NULL;
    printf("Enter the size of the array of sweetness: ");
    int size = 0;
    scanf("%d", &size);

    printf("\nEnter the array of sweetness: ");
    int* arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    int k = 0;
    printf("\nEnter the threshold value: ");
    scanf("%d", &k);

    for (int i = 0; i < size; i++) {
        addlast(arr[i], &List);
    }
    int ab=function(List, size, k);
    printf("The returned integer is: %d\n\n",ab );
    if(ab==0)
    printf("There are not enough sweets.\n");
    if(ab==-1)
    printf("The Sweets already have sweetness above the threshold.");
    return 0;
}
