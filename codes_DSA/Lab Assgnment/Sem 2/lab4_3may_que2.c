#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    if (top == 100 - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }}

void infix_to_prefix(char infix[], char prefix[]) {
    int i, j;
    char c;

    reverse(infix);

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(infix[i]);
        } else if (infix[i] == '(') {
            while ((c = pop()) != ')') {
                prefix[j++] = c;
            }
        } else {
            while (precedence(infix[i]) <= precedence(stack[top]) && top != -1) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    reverse(prefix);
}

int main() {
    char infix[100], prefix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);
    reverse(infix);
    printf("The expression you entered in reverse is : %s\n",infix);
    reverse(infix);
    infix_to_prefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
