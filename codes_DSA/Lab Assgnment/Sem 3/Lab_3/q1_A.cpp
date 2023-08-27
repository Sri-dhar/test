#include <bits/stdc++.h>

int DNC(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int mid = (left + right) / 2;
    int leftMax = DNC(arr, left, mid); 
    int rightMax = DNC(arr, mid + 1, right); 

    return std::max(leftMax, rightMax);
}

int main() {
    std::cout << "Enter the size of the array: ";
    int n;
    std::cin >> n;
    int arr[n];
    
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    int max = DNC(arr, 0, n - 1);
    std::cout << "The maximum element in the array is: " << max << std::endl;
    
    return 0;
}
