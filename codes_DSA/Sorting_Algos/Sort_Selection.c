#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(int *arr, int n)
{
    for (int im = 0; im < n; im++)
    {
        int min = arr[im];
        int min_idx = im;

        for (int i = im; i < n; i++)
        {
            if (arr[i] < min)
            {
                min_idx = i;
            }
        }

        swap(&arr[min_idx], &arr[im]);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    return 0;
}
