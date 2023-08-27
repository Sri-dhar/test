#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n ;i++) cin>>arr[i];
    int bestmax = INT_MIN;
    int bestmaxidx = 0;
    for(int i=0;i<n ;i++)
    {
        if(isPrime(arr[i])) {
            bestmax = max(bestmax,arr[i]);
            bestmaxidx = i;
        }
        
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