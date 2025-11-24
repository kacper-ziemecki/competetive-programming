#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
ll dfs(ll u, vector<vector<ll>> &adj, vector<bool> &vis){
  vis[u] = true;
  ll cnt = 1;
  for(auto v : adj[u]){
    if(!vis[v]){
      cnt += dfs(v, adj, vis);
    }
  }
  return cnt;
}

void solve(ll n, ll m){
  vector<vector<ll>> list(m, vector<ll>(3));
  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < 3; j++) cin >> list[i][j];
  }
  ll maks = LLONG_MIN;
  for(auto el : list) maks = max(maks, el[2]);
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1);
  for(auto el : list){
    if(el[2] == maks){
      adj[el[0]].push_back(el[1]);
      adj[el[1]].push_back(el[0]);
    }
  }
  ll res = 0;
  for(ll i = 0; i < n+1; i++){
    if(!vis[i]){
      res = max(res, dfs(i, adj, vis));
    }
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
  
  
  ll n, m;
  while(cin >> n >> m, n != 0 && m != 0){
    solve(n, m);
  }
}