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

ll n,m,u,v;
ll const maxLiczba = 1e5+1;
vector<ll> adj[maxLiczba], adj_t[maxLiczba];
ll dp[maxLiczba];
bool vis[maxLiczba];
vector<ll> topo;

void dfs(ll u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) dfs(v);
  }
  topo.pb(u);
}
void solve()
{
  cin >> n >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj_t[v].pb(u);
  }

  for(ll u = 1; u <= n; u++){
    if(!vis[u]) dfs(u);
  }
  reverse(topo.begin(), topo.end());
  ll res = 0;
  for(ll u : topo){
    for(ll v : adj_t[u]){
      dp[u] = max(dp[u], dp[v]+1);
      res = max(res, dp[u]);
    }
  }
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}