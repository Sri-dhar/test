#include <iostream>
#include <vector>

int findPeak(int *arr, int l, int r)
{
    if (l == r)
    {
        return arr[l];
    }

    int mid = l + ((r - l) / 2);

    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
    {
        return arr[mid];
    }
    else if (arr[mid] >= arr[mid + 1] && arr[mid] <= arr[mid - 1])
    {
        return findPeak(arr, l, mid - 1);
    }
    else if (arr[mid] >= arr[mid - 1] && arr[mid] <= arr[mid + 1])
    {
        return findPeak(arr, mid + 1, r);
    }
    else if (arr[mid] <= arr[mid - 1] && arr[mid] <= arr[mid + 1])
    {
        if (arr[mid - 1] >= arr[mid + 1]) return findPeak(arr, l, mid - 1);
        else return findPeak(arr, mid + 1, r);
    }

    return -1;
}

int main()
{
    std::cout << "Enter the size of the array: ";
    int n{};
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        arr[i] = temp;
    }

    int *arrPtr = &arr[0];

    std::cout << "The peak element is: " << findPeak(arrPtr, 0, n - 1) << std::endl;
    return 0;
}
