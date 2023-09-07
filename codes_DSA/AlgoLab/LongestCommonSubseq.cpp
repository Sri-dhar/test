#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//simple top down
int LCS(string a, string b,int m,int n) {
        if(m==0 || n==0) return 0;
        if(a[m-1]==b[n-1]) 
            return 1+LCS(a,b,m-1,n-1);
        else 
            return max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));
}

//memoized code 
vector<vector<int>> memo(1000, vector<int>(1000, -1));

int LCSmemo(string a, string b,int m,int n){
        if(m==0 || n==0) return 0;
        if(memo[m][n] != -1) return memo[m][n];
        if(a[m-1]==b[n-1]) 
            return memo[m][n] = 1+LCS(a,b,m-1,n-1);
        else 
            return memo[m][n] = max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));
}

//dp bottom up
int LCSdp(string a, string b, int m, int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++) dp[i][0]=0;
    for(int i=0;i<n+1;i++) dp[0][i]=0;

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}


int main()
{
    std::string a, b;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;

    int ans = LCSdp(a, b, a.size(), b.size()); //subsequence
    cout << "The length of the Longest Common Substring is: " << ans << endl;

    return 0;
}