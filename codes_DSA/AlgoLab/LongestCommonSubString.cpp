#include <iostream>
#include <algorithm>
#include <vector>
//Longest Common Sub Word / SubString

//Testcase :: "helloworldair"   and   "helloair"   output should be 5 (hello)
using namespace std;

int LCSrec(string a, string b, int m, int n, int count) {
    
    if (m == 0 || n == 0) return count;
    if (a[m - 1] == b[n - 1]) count = LCSrec(a, b, m - 1, n - 1, count + 1);

    count = max(count, max(LCSrec(a, b, m - 1, n, 0), LCSrec(a, b, m, n - 1, 0)));
    return count;
}


int LCSrecMemo(string a, string b, int m, int n, vector<vector<int>>& memo,int count) {
    
    if (m == 0 || n == 0) return count;
    if (memo[m][n] != -1) return memo[m][n];
    if (a[m - 1] == b[n - 1]) count = LCSrec(a, b, m - 1, n - 1, count + 1);

    count = max(count, max(LCSrec(a, b, m - 1, n, 0), LCSrec(a, b, m, n - 1, 0)));
    return memo[m][n] = count;
}

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
    cout << "Using DP, length of LCS is : " << result << endl;

    vector<vector<int>> memo(a.length() + 1, vector<int>(b.length() + 1, -1));
    result = LCSrecMemo(a, b, a.length(), b.length(), memo ,0);
    cout << "Using rec + memo length of LCS is : " << result << endl;

    result = LCSrec(a,b,a.size(),b.size(),0);
    cout<< "Using rec ,length of LCS is : "<<result<<endl;

    return 0;
}
