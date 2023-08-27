#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    a+= (c/2 + c%2);
    b+= c/2;
    if(a>b) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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