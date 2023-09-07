#include<iostream>
#include<vector>
#include<algorithm>

int knapsack(std::vector<int>& arr, int size) {
    int n = arr.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(size + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= size; ++j) {
        dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = size; j >= 0; --j) {
            if (arr[i] <= j) {
                int inc = arr[i] + dp[i + 1][j - arr[i]];
                int exc = dp[i + 1][j];
                dp[i][j] = std::max(inc, exc);
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return dp[0][size];
}


int main() {
    std::vector<int> objects;
    int temp;
    while (true) {
        std::cin >> temp;
        if (temp != -1)
            objects.push_back(temp);
        else
            break;
    }

    int size;
    std::cin >> size;

    int ans = knapsack(objects, size);

    std::cout << ans << std::endl;

    return 0;
}
