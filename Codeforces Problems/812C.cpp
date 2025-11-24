#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll check(vector<ll> &list, ll s, ll m){
  vector<ll> res(list.size());
  for(ll i = 0; i < list.size(); i++) res[i] = list[i] + (i+1)*m;
  sort(res.begin(), res.end());
  for(ll i = 0; i < m; i++) s -= res[i];
  return s;
}

void solve()
{
  ll n,s;
  cin >> n >> s;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  ll l = 0, r = n, res = 0;
  while(l < r){
    ll m = (l+r+1)/2;
    // dbg(l,m,r);
    ll cur = check(list,s,m);
    if(cur >= 0){ l = m; res = s-cur; }
    else r = m-1;
  }
  cout << l << " " << res << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}