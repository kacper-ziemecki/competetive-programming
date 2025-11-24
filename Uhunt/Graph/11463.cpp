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
  vector<vector<ll>> am(n, vector<ll>(n, LLONG_MAX));
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    am[u][v]=1;
    am[v][u]=1;
  }
  for(ll i = 0; i < n; i++) am[i][i]=0;

  for(ll k = 0; k < n; k++){
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        if(am[i][k]==LLONG_MAX||am[k][j]==LLONG_MAX) continue;
        am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
      }
    }
  }
  cin >> u >> v;
  ll res = am[u][v];
  for(ll k = 0; k < n; k++){
    if(am[u][k]==LLONG_MAX||am[k][v]==LLONG_MAX) continue;
    res = max(res, am[u][k]+am[k][v]);
  }
  cout << res << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    cout << "Case " << i << ": ";
    solve();
  }
}