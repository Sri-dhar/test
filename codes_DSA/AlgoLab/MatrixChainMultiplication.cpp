#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>

int MCM_topDown(int i, int j, std::vector<int> &arr)
{
    if (i == j) return 0;
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM_topDown(i, k, arr) + MCM_topDown(k + 1, j, arr);
        if (steps < mini) mini = steps;
    }
    return mini;
}

int MCM_topDownMemo(int i, int j, std::vector<std::vector<int>> &memo, std::vector<int> &arr)
{
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MCM_topDownMemo(i, k, memo, arr) + MCM_topDownMemo(k + 1, j, memo, arr);
        if (steps < mini) mini = steps;
    }
    return memo[i][j] = mini;
}

int MCM_dp(std::vector<int> &arr)
{
    int N = arr.size();
    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i < N - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (steps < dp[i][j])
                {
                    dp[i][j] = steps;
                }
            }
        }
    }
    return dp[1][N - 1];
}

int main()
{
    std::cout << "Enter the array of matrices dimensions : " << std::endl;
    std::cout << "Enter -1 to stop" << std::endl;
    std::vector<int> arr;
    int temp{};
    while (1)
    {
        std::cin >> temp;
        if (temp == -1) break;
        arr.push_back(temp);
    }

    std::chrono::steady_clock::time_point start, end;
    start = std::chrono::steady_clock::now();
    int ans1 = MCM_topDown(1, arr.size() - 1, arr);
    end = std::chrono::steady_clock::now();
    std::cout << "MCM_TopDown     " << ans1 << " (Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms)" << std::endl;

    std::vector<std::vector<int>> memo(arr.size(), std::vector<int>(arr.size(), -1));
    start = std::chrono::steady_clock::now();
    int ans2 = MCM_topDownMemo(1, arr.size() - 1, memo, arr);
    end = std::chrono::steady_clock::now();
    std::cout << "MCM_TopDownMemo " << ans2 << " (Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms)" << std::endl;

    start = std::chrono::steady_clock::now();
    int ans3 = MCM_dp(arr);
    end = std::chrono::steady_clock::now();
    std::cout << "MCM_Dp          " << ans3 << " (Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms)" << std::endl;
}
