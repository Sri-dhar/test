#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char arr[200];
    int top;
} Stack;
typedef struct Stack *  sttack;

void init(sttack s) {
    s->top = -1;
}

int isFull(sttack s) {
    return s->top == 200 - 1;
}

int isEmpty(sttack s) {
    return s->top == -1;
}

void push(sttack s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = c;
}

char pop(sttack s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[s->top--];
}

void reverseWords(char* str) {
    Stack s;
    init(&s);
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            push(&s, str[i]);
        } else {
            while (!isEmpty(&s)) {
                printf("%c", pop(&s));
            }
            printf(" ");
        }
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
}

int main() {
    char str[200];
    printf("Enter a string: ");
    fgets(str, 200, stdin);
    printf("Reversed string: ");
    reverseWords(str);
    printf("\n");
    return 0;
}
