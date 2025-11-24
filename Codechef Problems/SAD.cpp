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
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(m));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++) cin >> list[i][j];
  }
  vector<ll> rows(n), columns(m);
  for(ll i = 0; i < n; i++){
    ll res = LLONG_MAX;
    for(ll j = 0; j < m; j++) res = min(res, list[i][j]);
    rows[i] = res;
  }
  for(ll i = 0; i < m; i++){
    ll res = LLONG_MIN;
    for(ll j = 0; j < n; j++) res = max(res, list[j][i]);
    columns[i] = res;
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(list[i][j] == rows[i] && list[i][j] == columns[j]){
        cout << list[i][j] << endl;
        return;
      }
    }
  }
  cout << "GUESS\n";
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