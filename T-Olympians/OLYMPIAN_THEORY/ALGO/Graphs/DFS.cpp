#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void dfs(int u, vector<vector<int>>& adj, vector<bool> &vis, vector<int>& res){
  res.pb(u);
  vis[u] = true;
   for(auto v : adj[u]){
    if(!vis[v]) dfs(v,adj,vis,res);
  }
}


int main()
{
  // 5 6
  // 1 3
  // 4 3
  // 3 2
  // 2 4
  // 5 4
  // 3 1
  int n,m;
  int u,v;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<bool> vis(n+1, false);
  vector<int> res;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
  }
  dfs(1,adj,vis,res);
  for(auto el : res) cout << el << ' ';
  cout << endl;
}