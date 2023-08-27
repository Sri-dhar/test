#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    string binaryString; 
    cin >> binaryString;
    
    int first = 0, last = n - 1;
    while (binaryString[first] != binaryString[last] && first < last)
    {
        first++;
        last--;
    }
    cout << last - first + 1 << endl;
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
