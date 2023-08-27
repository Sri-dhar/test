#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int getElement(int arr[], int n, int k) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = 0; i < k - 1; i++) {
        swap(&arr[0], &arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }

    return arr[0];
}

int main() {
    printf("Enter the size of the array : ");
    int n=0; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    printf("Enter the array :");
    for(int i=0;i<n ;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Enter the value of k : ");
    int k=0;
    scanf("%d",&k);
    int kthLargest = getElement(arr, n, k);

    printf("The %dth largest element is: %d\n", k, kthLargest);

    return 0;
}
