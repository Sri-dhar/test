#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int LCS(string a, string b) {
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}

int main() {
    std::string a, b;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;

    int result = LCS(a, b);
    cout << "The length of the Longest Common Substring is: " << result << endl;

    return 0;
}
