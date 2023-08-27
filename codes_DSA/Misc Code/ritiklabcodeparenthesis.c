#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void create_stack(struct Stack* stack) {
    stack->top = -1;
}

int is_empty(struct Stack* stack) {
    return (stack->top == -1)? 1:0;
}

int is_full(struct Stack* stack) {
    return ( stack->top == MAX_SIZE - 1) ? 1:0;
}

void push(struct Stack* stack, char bracket) {
    if (!is_full(stack)) {
        stack->items[++stack->top] = bracket;
    } else {
        printf("Error: Stack overflow!\n");
    }
}

char pop(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Error: Stack underflow!\n");
        return '\0';
    }
}

int is_matching_pair(char open_bracket, char close_bracket) {
    if (open_bracket == '(' && close_bracket == ')') {
        return 1;
    } else if (open_bracket == '[' && close_bracket == ']') {
        return 1;
    } else if (open_bracket == '{' && close_bracket == '}') {
        return 1;
    } else {
        return 0;
    }
}

int is_balanced(char brackets[]) 
{
    struct Stack stack;
    create_stack(&stack);

    for (int i = 0; brackets[i] != '\0'; i++) {
        char bracket = brackets[i];

        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(&stack, bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (is_empty(&stack) || !is_matching_pair(pop(&stack), bracket)) {
                return false;
            }
        }
    }

    return is_empty(&stack) ? 1:0;
}

int main() {
    char brackets[MAX_SIZE];
    printf("Enter a string of brackets: ");
    scanf("%s", brackets);

    if (is_balanced(brackets)) {
        printf("The brackets are balanced!\n");
    } else {
        printf("The brackets are not balanced!\n");
    }

    return 0;
}
