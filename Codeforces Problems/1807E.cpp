#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(ll m, ll pref){
  ll k = ++m;
  cout << "? " << k << " ";
  for(ll i = 1; i <= m; i++) cout << i << " ";
  cout << endl;
  ll sum;
  cin >> sum;
  return sum == pref;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n), pref(n);
  for(auto &el : list) cin >> el;
  pref[0] = list[0];
  for(ll i = 1; i < n; i++) pref[i] = pref[i-1] + list[i];
  ll l = 0, r = n-1;
  while(l < r){
    ll m = (l+r)/2;
    if(check(m, pref[m])) l = m+1;
    else r = m;
  }
  cout << "! " << r+1 << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}