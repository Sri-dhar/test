#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define rep(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define sz(x) ((int)(x).size())

void solve()
{
ll n,m,i,j,k;
//ll n;
cin>>n;
vll a(n),b(n);
rep(i,n)
cin>>a[i];
rep(i,n)
cin>>b[i];
vector<pll>ans;
ll mx=-1e18;
rep(i,n)
{
  ans.pb({a[i]-b[i],i+1});
  mx=max(mx,a[i]-b[i]);
}
vll cnt;
rep(i,n)
{
  if(ans[i].first==mx)
  {
    cnt.push_back(ans[i].second);
  }
}
cout<<sz(cnt)<<endl;
for(auto it:cnt)
cout<<it<<" ";
cout<<endl;
}

signed main()
{

  ll t;
  cin>>t;
  while(t-->0)
  solve();
  
}