#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int linearSearch(char *arr[], int n, char *inputString) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(arr[i], inputString) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char *arr[n];
    printf("Enter the list of strings:\n");
    for (int i = 0; i < n; i++) {
        char str[100];
        printf("String %d: ", i + 1);
        scanf("%s", str);
        arr[i] = strdup(str);
    }

    char inputString[100];
    printf("Enter the search string: ");
    scanf("%s", inputString);

    int index = linearSearch(arr, n, inputString);
    if (index != -1) {
        printf("The first occurrence of \"%s\" is found at index %d.\n", inputString, index);
    } else {
        printf("The search string \"%s\" is not found.\n", inputString);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}
