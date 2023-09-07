#include<iostream>
#include<algorithm>
#include<vector>

int LCS(std::string a, std::string b, int i, int j, int count)
{
    if (i == 0 || j == 0) return count;

    if (a[i - 1] == b[j - 1]) count = LCS(a, b, i - 1, j - 1, count + 1);

    count = std::max(count, std::max(LCS(a, b, i - 1, j, 0), LCS(a, b, i, j - 1, 0)));

    return count;
}

int main()
{
    std::string a, b;
    std::cout << "Enter the first string: ";
    std::cin >> a;
    std::cout << "Enter the second string: ";
    std::cin >> b;

    int m = a.length();
    int n = b.length();

    int length = LCS(a, b, m, n, 0);

    std::cout << "Length of Longest common Subword is " << length << std::endl;

    return 0;
}