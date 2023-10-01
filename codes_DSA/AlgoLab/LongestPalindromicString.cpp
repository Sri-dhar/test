#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<climits>
#include<cmath>

using namespace std;

double maximum(double a, int b)
{
    return (a > b) ? a : b;
}

int LPS(string s)
{
    int size = s.size();
    double maxi = INT_MIN;
    vector<vector<int>> grid(size + 1, vector<int>(size + 1, 0));
    for (int i = 1; i <= size; i++)
    {
        for (int j = size - 1; j >= 0; j--) 
        {
            if (s[i - 1] == s[j] && i - 1 != j)
            {
                grid[i][j] = 2 + grid[i - 1][j + 1]; 
            }
            else if (s[i - 1] == s[j] && i - 1 == j)
            {
                grid[i][j] = 1 + grid[i - 1][j + 1];
            }
            maxi = maximum(maxi, grid[i][j]); 
        }
    }
    return ceil(maxi / 2.0); 
}

int main()
{
    cout << "Enter the string: ";
    string s;
    cin >> s;
    int len = LPS(s);
    cout << "The length of the longest palindromic subsequence is: " << len;
    return 0;
}
