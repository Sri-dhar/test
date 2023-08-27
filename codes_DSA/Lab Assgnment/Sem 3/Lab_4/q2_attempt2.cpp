// CORRECT ONE
#include <iostream>
#include <vector>

int counter(std::vector<int>& arr, int num, int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) if (arr[i] == num) count++;
    return count;
}

int FindMajor(std::vector<int>& arr, int low, int high) {
    if (low > high) {
        return -1;
    }

    if (low == high) {
        return arr[low];
    }

    int mid = low + (high - low) / 2;

    int lMajor = FindMajor(arr, low, mid);
    int rMajor = FindMajor(arr, mid + 1, high);

    int leftCount = counter(arr, lMajor, low, high);
    int rightCount = counter(arr, rMajor, low, high);

    int majorityThreshold = (high - low + 1) / 2;
    
    if (leftCount > majorityThreshold) {
        return lMajor;
    } else if (rightCount > majorityThreshold) {
        return rMajor;
    } else {
        return -1;
    }
}

int main() {
    std::cout << "Enter the size of the array: ";
    int n{};
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter the array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int majority = FindMajor(arr, 0, n - 1);

    std::cout << "The majority element is ";
    if (majority != -1) {
        std::cout << majority << std::endl;
    } else {
        std::cout << "not present" << std::endl;
    }

    return 0;
}
