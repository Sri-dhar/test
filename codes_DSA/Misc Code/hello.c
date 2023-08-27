#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int size_g = 0;

int* stackcreator() {
    printf("Enter the size of stack you want to create: ");
    int size = 0;
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid stack size\n");
        return NULL; // add error handling for invalid sizes
    }
    
    size_g = size;
    int* arr = (int*)calloc(size, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL; // add error handling for calloc failure
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = INT_MIN;
    }
    
    return arr;
}

void push(int* arr, int data, int** stack_cpy) {
    for (int i = 0; i < size_g; i++) {
        if (*(arr + i) == INT_MIN) {
            *(arr + i) = data;
            (*stack_cpy) += sizeof(int); // increment by size of integer
            return; // return after successful push
        }
    }
    
    printf("Stack overflow\n"); // add error handling for full stack
}

void printstack(int* stack) {
    for (int i = size_g - 1; i >= 0; i--) { // fix loop bounds
        if (*(stack + i) != INT_MIN) {
            printf("|------|\n");
            printf("|__%d__|\n", *(stack + i));
        }
    }
}

int main() {
    int* stack = stackcreator();
    
    if (stack == NULL) {
        return -1; // add error handling for failed stack creation
    }
    
    int* stack_cpy = stack;
    push(stack, 45, &stack_cpy);
    push(stack, 44, &stack_cpy);
    push(stack, 43, &stack_cpy);
    printstack(stack);
    
    free(stack); // free allocated memory
    
    return 0;
}
