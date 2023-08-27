#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void solve()
{
	int n; cin>>n;
	if(n%2 == 1)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<n<<" ";
		}
		
		cout<<"\n";
	}
	else
	{
		for(int i=1;i<=n-2;i++)
		{
			cout<<2<<" ";
		}
		cout<<3<<" "<<1<<"\n";
	}
	
 
 
}

int main()
{
    IOS 

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
