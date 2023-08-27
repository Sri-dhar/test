#include<bits/stdc++.h>

int main()
{
    std::cout << "Enter the array elements" << std::endl;
    std::cout << "Enter -1 to stop :";
    std::vector<int> arr;
    int temp;

    while (true) {
        std::cin >> temp;
        if (temp != -1) arr.push_back(temp);
        else break;
    }

    int k;
    std::cout << "Enter the value of k (1-based index): ";
    std::cin >> k;

    if (k >= 1 && k <= arr.size()) {
        int kthSmallest = medofmed(arr, k);
        std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;
    } else {
        std::cout << "Invalid value of k." << std::endl;
    }

    return 0;

}