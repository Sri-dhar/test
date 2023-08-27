#include<iostream>
int memo[1000];
int myLog(int n) {
    int result = -1;
    while (n > 0) {
        n >>= 1;
        result++;
    }
    return result;
}

int ans(int n)
{
    //memo[height] = node max value
    memo[0] = 1;
    memo[1] = 2;
    if (n == 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i < n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2] + 1;
        if (memo[i] == n) return i;
        if (memo[i] > n && memo[i - 1] < n) return i - 1;
    }
    return 0;
}

int main() {
    int n{};
    std::cout << "Enter the number of nodes: " << std::endl;
    std::cin >> n;
    std::cout << "The maximum height of the tree is: " << ans(n)   << std::endl;
    std::cout << "The minimum height of the tree is: " << myLog(n) << std::endl;
    return 0;
}