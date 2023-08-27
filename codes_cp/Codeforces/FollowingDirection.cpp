#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
void solve()
{

    int n;
    cin>>n;

    string s;
    cin>>s;
 
    pair<int,int>start={0,0};
    pair<int,int>dest={1,1};
    bool flag=false;
    for(auto &it:s)
    {
       if(it=='L')
       {
           start.first--;
       }
       else if(it=='R')
       {
           start.first++;
       }

       else if(it=='U')
       {
           start.second++;
       }
       else if(it=='D')
       {
           start.second--;

       }
        if(start==dest){
            flag=1;
            break;
        }
     }
     if(flag==true)
     {
        cout<<"YES"<<endl;
     }
     else cout<<"NO"<<endl;
 
}

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
