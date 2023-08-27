#include <iostream>
#include <vector>
#include<climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{   
    IOS
    int n;
    cin>>n;
    vector<int> arr(n);
    int max = INT_MIN;
    for(int i=0; i<n ;i++) {
        int temp = 0;
        cin>>temp;
        arr.push_back(temp);
    }
    int noo{};
    for(auto i: arr)
    {
        if(i==1) noo++;
    }
    if(noo%2){
        std::cout<<n-noo/2<<std::endl;
    }
    else{
        std::cout<<n-noo/2<<std::endl;
    }

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}