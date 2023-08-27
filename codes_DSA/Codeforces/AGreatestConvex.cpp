#include <iostream>
#include <vector>
typedef long long ll;
// std::vector<ll> dp(1e9 + 1, -1);

// ll fact(ll a) {
//     if (a == 0) return 1;
//     if (dp[a] != -1) return dp[a];
//     return dp[a] = a * fact(a - 1);
// }

// int main() {
//     dp[0] = 1;
//     int t{};
//     std::cin >> t;
//     while (t--) {
//         ll k{};
//         std::cin >> k;
//         for (ll i = k - 1; i >= 2; i--) {
//             if ((fact(i) + fact(i - 1)) % k == 0) {
//                 std::cout << i << std::endl;
//                 break;
//             }
//         }
//     }
//     return 0;
// }
int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        ll k;
        std::cin>>k;
        std::cout<< k-1<<std::endl;
    }
    return 0;
}