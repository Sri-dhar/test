#include <stdio.h>
#include <string.h>

void insertionSort(char *arr[], int n) {
    int i, j;
    char temp[100];

    for (i = 1; i < n; i++) {
        strcpy(temp, arr[i]);
        j = i - 1;

        while (j >= 0 && strcmp(arr[j], temp) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }

        strcpy(arr[j + 1], temp);
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();
    char arr[n][100];
    printf("Enter the list of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: ", i + 1);
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; 
    }

    char *ptrs[n];
    for (int i = 0; i < n; i++) {
        ptrs[i] = arr[i];
    }

    insertionSort(ptrs, n);

    printf("Sorted list of strings: [");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", ptrs[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
