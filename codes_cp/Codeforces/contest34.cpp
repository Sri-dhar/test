#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    int cur = 1;
    while (cur <= n)
    {
        cout << cur << " ";
        v[cur] = 1;
        cur *= 2;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            cout << i << " ";
            v[i] = 1;
            if (i * 2 <= n)
            {
                cout << i * 2 << " ";
                v[i * 2] = 1;
            }
        }
    }

    cout << endl;
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
