#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int comparator(const void *p, const void *q) {
    return (*(int *)p - *(int *)q);
}

int main() {
    printf("Enter the size of the array: ");
    int size = 0;
    scanf("%d", &size);

    printf("Enter the array: ");
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    qsort((void *)arr, size, sizeof(arr[0]), comparator);

    int min = arr[0];
    int max = arr[size - 1];

    printf("Missing numbers between %d and %d: ", min, max);

    int *arr_temp = (int *)calloc(MAXSIZE, sizeof(int));

    for (int i = min + 1; i < max; i++) {
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", i);
        }
    }

    free(arr);
    free(arr_temp);

    return 0;
}
