#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a-1 == (abs(b-c)+(c-1))) cout<<3<<endl;
    else if(a-1 > (abs(b-c)+(c-1))) cout<<2<<endl;
    else if(a-1 < (abs(b-c)+(c-1))) cout<<1<<endl;
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