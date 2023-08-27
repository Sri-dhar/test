#include <stdio.h>
#include <string.h>

int main() {
    char string[100], reverse_string[100];
    int length, i, j;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    length = strlen(string);

    j = 0;
    for (i = length - 1; i >= 0; i--) {
        reverse_string[j++] = string[i];
    }

    reverse_string[j] = '\0';

    printf("Original string: %s", string);
    printf("Reversed string: %s", reverse_string);

    return 0;
}
