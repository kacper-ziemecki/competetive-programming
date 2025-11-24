#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& deg){
  vis[u] = true;
  bool res=true;
  for(auto v : adj[u]){
    if(!vis[v] && !dfs(v, adj, vis, deg)) res = false;
  }
  if(deg[u] != 2) res = false;
  return res;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1, false);
  vector<ll> deg(n+1, 0);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  ll res=0;
  for(ll i = 1; i <= n; i++){
    if(!vis[i] && dfs(i, adj, vis, deg)) res++;
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