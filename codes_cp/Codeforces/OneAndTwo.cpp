#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

void solve()
{
    int size{};
    cin >> size;
    int twos{};
    vector<int> arr(size);
    for(int i=0; i<size; i++) {
        cin>>arr[i];
        if(arr[i] == 2) twos++;
    }
    int twocount{};
    for(int i=0; i<size; i++)
    {
        if(arr[i]==2) twocount++;
        if(twocount*2 == twos){
            cout<<i+1<<endl;
            return;
        }
    }
    std::cout << "-1" << std::endl;
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
