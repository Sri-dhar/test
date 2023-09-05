#include<iostream>
#include<vector>
#include<algorithm>

int func(std::vector<int>& arr, int size, int idx, std::vector<std::vector<int>>& dp) {
    if (idx == arr.size() || size <= 0)
        return 0;
    
    if (dp[idx][size] != -1)
        return dp[idx][size];
    
    if (arr[idx] <= size) {
        int a = arr[idx] + func(arr, size - arr[idx], idx + 1, dp);
        int b = func(arr, size, idx + 1, dp);
        return dp[idx][size] = std::max(a, b);
    }
    else
        return dp[idx][size] = func(arr, size, idx + 1, dp);
}

int main() {
    std::cout << "Enter the objects of the knapsack:" << std::endl;
    std::cout << "Enter -1 to stop" << std::endl;
    std::vector<int> objects;
    int temp;
    while (true) {
        std::cin >> temp;
        if (temp != -1)
            objects.push_back(temp);
        else
            break;
    }
    
    int osize = objects.size();
    
    std::cout << "Enter the size of knapsack:" << std::endl;
    int size;
    std::cin >> size;
    
    std::vector<std::vector<int>> dp(osize + 1, std::vector<int>(size + 1, -1));
    int ans = func(objects, size, 0, dp);
    
    std::cout << "Answer is: " << ans << std::endl;
    
    return 0;
}