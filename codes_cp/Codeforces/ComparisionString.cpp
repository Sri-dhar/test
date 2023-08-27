#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin>>n;
    string str="";
    int count{};
    int max_count{};
    for(int i=0 ;i<n ; i++) cin>>str[i];
    for(int i=1 ;i<n ; i++)
    {
        while((str[i]=='>' && str[i-1]=='>' )||( str[i]=='<' && str[i-1]=='<'))
        { count++; i++; }
        max_count = max(count,max_count);
    }
    cout<<max(2,max_count+1)<<endl;
}

int main()
{
    IOS // Uncomment this line if you want to use fast I/O

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}