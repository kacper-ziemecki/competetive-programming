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




void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> list(n, vector<ll>(5));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 5; j++) cin >> list[i][j];
  }
  vector<ll> cur  = list[0];
  ll idx = 0;
  for(ll i = 1; i < n; i++){
    ll cnt = 0;
    for(ll j = 0; j < 5; j++){
      if(cur[j] < list[i][j]) cnt++;
    }
    if(cnt < 3){ cur = list[i]; idx = i; }
  }
  bool flag = true;
  for(ll i = 0; i < n; i++){
    if(i == idx) continue;
    ll cnt = 0;
    for(ll j = 0; j < 5; j++){
      if(cur[j] < list[i][j]) cnt++;
    }
    if(cnt < 3) flag = false;
  }
  if(!flag) cout << -1 << endl;
  else cout << idx+1 << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();
}