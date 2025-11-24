#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll n){
  vector<vector<ll>> am(n+1, vector<ll>(n+1, LLONG_MAX)), p(n+1, vector<ll>(n+1, 0));
  ll m,u,v,w;
  for(ll i = 0; i < n; i++){
    cin >> m;
    for(ll j = 0; j < m; j++){
      cin >> u >> w;
      am[i+1][u]=min(am[i+1][u],w);
    }
  }
  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= n; j++) p[i][j]=i;
  }
  for(ll k = 1; k <= n; k++){
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= n; j++){
        if(am[i][k]==LLONG_MAX||am[k][j]==LLONG_MAX) continue;
        if(am[i][k]+am[k][j] < am[i][j]){
          am[i][j] = am[i][k]+am[k][j];
          p[i][j] = p[k][j];
        }
      }
    }
  }
  cin >> u >> v;
  ll s = u, d = v;
  vector<ll> res;
  while(v != u){
    res.push_back(v);
    v = p[u][v];
  }
  res.push_back(u);
  reverse(res.begin(), res.end());
  cout << "Path = ";
  for(ll i = 0; i < res.size(); i++){
    if(i!=0) cout << " ";
    cout << res[i];
  }
  cout << "; ";
  cout << am[s][d] << " second delay\n";
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
  
  ll n;
  ll t=1;
  while(cin >> n, n != 0){
    cout << "Case " << t++ << ": ";
    solve(n);
  }
}