#include <bits/stdc++.h>
using namespace std;

// const int maxn = 100;
// vector<int> adj1[maxn];
void dfs(int u, vector<bool> &vis){
  vis[u] = true;
  for(int v : adj[u]){
    if(!vis[v]) dfs(v);
  }
}

int main()
{
  int n,m;
  int u,v;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<bool> vis(n+1);
  // vector<pair<int,int>> edges;
  for(auto i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    // edges.push_back({u,v});
  }
  dfs(1,vis);
  return 0;
}