#include <iostream>
#include <climits>

std::pair<int, int> MinMaxDAC(int A[], int i, int j) {
    
    std::pair<int, int> ans;

    if (i == j) 
    {
        ans.first = A[i];
        ans.second = A[i];
    }
    else if ((j - i) == 1) {
        if (A[i] < A[j]) {
            ans.first = A[i];
            ans.second = A[j];
        }
        else {
            ans.first = A[j];
            ans.second = A[i];
        }
    }
    else {
        int mid = (i + j) / 2;
        std::pair<int, int> leftResult = MinMaxDAC(A, i, mid);
        std::pair<int, int> rightResult = MinMaxDAC(A, mid + 1, j);

        if (leftResult.second > rightResult.second)
            ans.second = leftResult.second;
        else
            ans.second = rightResult.second;

        if (leftResult.first < rightResult.first)
            ans.first = leftResult.first;
        else
            ans.first = rightResult.first;
    }

    return ans;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::pair<int, int> minMax = MinMaxDAC(arr, 0, n - 1);
    std::cout << "The minimum element in the array is: " << minMax.first << std::endl;
    std::cout << "The maximum element in the array is: " << minMax.second << std::endl;

    return 0;
}
