#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

int findKthLargest(int arr[], int n, int k) {
    buildMinHeap(arr, k);

    for (int i = k; i < n; i++) {
        if (arr[i] > arr[0]) {
            swap(&arr[i], &arr[0]);
            minHeapify(arr, k, 0);
        }
    }

    return arr[0];
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    printf("Enter elements of the array (enter -1 to stop):\n");
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        arr[n++] = num;
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kthLargest = findKthLargest(arr, n, k);
    printf("The %dth largest array element is %d.\n", k, kthLargest);

    return 0;
}
