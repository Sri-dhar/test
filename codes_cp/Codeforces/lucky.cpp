#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    string str;
    cin >> str;
    if(str.length()==6)
    {
        int x = str[0] -'0';
        x += str[1]-'0';
        x += str[2]-'0';
        int y = str[3] -'0';
        y += str[4] -'0';
        y += str[5] -'0';
        if ( x == y) {
            cout<<"YES"<<endl;
            return;
        }
        else
        cout<<"NO"<<endl;
    }
    
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