#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(std::vector<int> &arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex - low == k - 1) {
            return arr[partitionIndex];
        } else if (partitionIndex - low > k - 1) {
            return kthSmallest(arr, low, partitionIndex - 1, k);
        } else {
            return kthSmallest(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
        }
    }

    return -1;
}

int medofmed(std::vector<int> &arr, int k) {
    int n = arr.size();
    std::vector<int> medians;

    for (int i = 0; i < n; i += 5) {
        int size = std::min(5, n - i);
        std::vector<int> subArray(arr.begin() + i, arr.begin() + i + size);
        std::sort(subArray.begin(), subArray.end());
        medians.push_back(subArray[size / 2]);
    }

    int median_of_medians = (medians.size() == 1) ? medians[0] : medofmed(medians, medians.size() / 2);

    int partitionIndex = partition(arr, 0, n - 1);

    if (k - 1 == partitionIndex) {
        return arr[partitionIndex];
    } else if (k - 1 < partitionIndex) {
        std::vector<int> leftPart(arr.begin(), arr.begin() + partitionIndex);
        return kthSmallest(leftPart, 0, leftPart.size() - 1, k);
    } else {
        std::vector<int> rightPart(arr.begin() + partitionIndex + 1, arr.end());
        return kthSmallest(rightPart, 0, rightPart.size() - 1, k - partitionIndex - 1);
    }
}
int main() {
    std::cout << "Enter the array elements" << std::endl;
    std::cout << "Enter -1 to stop :";
    std::vector<int> arr;
    int temp;

    while (true) {
        std::cin >> temp;
        if (temp != -1) {
            arr.push_back(temp);
        } else {
            break;
        }
    }

    int k;
    std::cout << "Enter the value of k : ";
    std::cin >> k;
    

    if (k >= 1 && k <= arr.size()) {
        int kthSmallest = medofmed(arr, k);
        std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;
    } else {
        std::cout << "Invalid value of k." << std::endl;
    }

    return 0;
}