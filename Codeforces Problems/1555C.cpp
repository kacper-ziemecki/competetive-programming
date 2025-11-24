#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n;
  cin >> n;
  vector<vector<ll>> list(2, vector<ll>(n)), prefix(2, vector<ll>(n)), suffix(2, vector<ll>(n));
  for(ll i = 0; i < 2; i++){
    for(ll j = 0; j < n; j++) cin >> list[i][j];
  }
  prefix[0][0] = list[0][0];
  prefix[1][0] = list[1][0];

  suffix[0][n-1] = list[0][n-1];
  suffix[1][n-1] = list[1][n-1];

  for(ll i = 0; i < 2; i++){
    for(ll j = 1; j < n; j++) prefix[i][j] = prefix[i][j-1]+list[i][j];
  }
  for(ll i = 0; i < 2; i++){
    for(ll j = n-2; j >= 0; j--) suffix[i][j] = suffix[i][j+1]+list[i][j];
  }
  // for(ll i = 0; i < 2; i++){
  //   for(ll j = 0; j < n; j++) cout << suffix[i][j] << " ";
  //   cout << endl;
  // }
  // cout << endl;
  ll res = LLONG_MAX;
  for(ll i = 0; i < n; i++){
    ll cur = max((i+1 < n ? suffix[0][i+1] : 0), (i-1 >= 0 ? prefix[1][i-1] : 0));
    // dbg(cur);
    res = min(res, cur);
  }
  cout << res << endl;
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