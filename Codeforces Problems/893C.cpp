#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll dfs(ll u, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &cost){
  ll res = cost[u];
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) res = min(res, dfs(v, adj, vis, cost));
  }
  return res;
}

void solve(){
  ll n,m,res=0;
  cin >> n >> m;
  vector<ll> cost(n);
  for(auto &el : cost) cin >> el;
  vector<vector<ll>> adj(n);
  vector<bool> vis(n, false);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    u--; v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  for(ll i = 0; i < n; i++){
    if(!vis[i]) res += dfs(i, adj, vis, cost);
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

  solve();

}