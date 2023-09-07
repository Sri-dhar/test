#include<bits/stdc++.h>

int fibo(int n )
{
    if(n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int fiboTopDown(int n, std::vector<int>& dp)
{
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fiboTopDown(n - 1, dp) + fiboTopDown(n - 2, dp);
}

int fiboBottomUp(int n)
{
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fiboBottomUpConstSpace(int n)
{
    int prev = 0, curr = 1, temp;
    if (n <= 1) return n;
    for (int i = 2; i <= n; i++)
    {
        temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

int main()
{
    std::cout << "Enter the value of n: ";
    int n;
    std::cin >> n;

    std::cout << "The " << n << "th fibonacci number by brute force is : " << fibo(n) << std::endl;

    std::vector<int> dp(n + 1, -1);
    std::cout << "The " << n << "th fibonacci number by dp + recursion is : " << fiboTopDown(n, dp) << std::endl;

    std::cout << "The " << n << "th fibonacci number by dp + bottom up + O(n) space is : " << fiboBottomUp(n) << std::endl;

    std::cout << "The " << n << "th fibonacci number by dp + bottom up + constant space is : " << fiboBottomUpConstSpace(n) << std::endl;
}
