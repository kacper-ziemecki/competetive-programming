#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
vector<unordered_set<ll>> adj,adj_new;
vector<vector<ll>> mp;
vector<ll> vis, dfs_num, dfs_low, mp1, topo;
stack<ll> S;
ll numDFS;

void tarjan(ll u){
  dfs_num[u] = dfs_low[u] = numDFS;
  numDFS++;
  vis[u] = 1;
  S.push(u);
  for(auto v : adj[u]){
    if(!dfs_num[v]) tarjan(v);
    if(vis[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if(dfs_num[u] == dfs_low[u]){
    vector<ll> res;
    while(S.top() != u){
      res.push_back(S.top());
      vis[S.top()] = 0;
      mp1[S.top()] = mp.size();
      S.pop();
    }
    mp1[u] = mp.size();
    vis[u] = 0;
    S.pop();
    res.push_back(u);
    mp.push_back(res);
  }
}
void toposort(ll u){
  vis[u] = true;
  for(ll v : adj_new[u]){
    if(!vis[v]) toposort(v);
  }
  topo.push_back(u);
}

void dfs(ll u){
  vis[u] = true;
  for(ll v : adj_new[u]){
    if(!vis[v]) dfs(v);
  }
}

void solve(){
  ll n,m,u,v;
  cin >> n >> m;

  adj.assign(n+1, {});
  vis.assign(n+1, 0);
  dfs_num.assign(n+1, 0);
  dfs_low.assign(n+1, 0);
  mp1.assign(n+1, 0);
  mp.clear();
  while(!S.empty()) S.pop();
  numDFS = 0;

  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].emplace(v);
  }
  for(ll u = 1; u <= n; u++){
    if(!dfs_num[u]){ numDFS++; tarjan(u); }
  }
  adj_new.assign(mp.size(), {});
  for(ll i = 0; i < mp.size(); i++){
    for(ll u : mp[i]){
      for(auto v : adj[u]){
        if(mp1[v] != i) adj_new[i].emplace(mp1[v]);
      }
    }
  }
  // for(ll i = 0; i < adj_new.size(); i++){
  //   cout << i << " : ";
  //   for(ll v : adj_new[i]) cout << v << " ";
  //   cout << endl;
  // }
  topo.clear();
  vis.assign(adj_new.size(), 0);
  for(ll u = 1; u < vis.size(); u++){
    if(!vis[u]) toposort(u);
  }
  reverse(topo.begin(), topo.end());
  // for(auto el : topo) cout << el << " ";
  // cout << endl;
  vis.assign(adj_new.size(), 0);
  ll res=0;
  for(auto u : topo){
    if(!vis[u]){ res++; dfs(u); }
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