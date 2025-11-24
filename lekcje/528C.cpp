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

void dfs(ll u, vector<vector<ll>>& adj, vector<vector<bool>>& vis, map<pair<ll,ll>,bool>& vis_edge, vector<ll>& euler){
  for(auto v : adj[u]){
    if(!vis[u][i]){
      vis[u][i] = true;
      vis[adj[u][i]][idx[u][i]] = true;
      dfs(adj[u][i],adj,vis,idx,euler);
    }
  }
  euler.pb(u);
}

void solve()
{
  ll n,m,edges=0;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
  vector<vector<bool>> vis(n+1);
  map<pair<ll,ll>,bool> vis_edge;
  vector<ll> deg(n+1);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    edges++;
    adj[u].pb(v);
    if(u!=v) adj[v].pb(u);
    idx[u].pb(adj[v].size()-1);
    if(u!=v) idx[v].pb(adj[u].size()-1);
    deg[u]++; deg[v]++;
  }
  vector<ll> odd_degs;
  for(ll i = 1; i <= n; i++) if(deg[i]&1) odd_degs.pb(i);
  // cout << "odd_degs:\n";
  // for(auto el : odd_degs) cout << el << " ";
  // cout << endl;
  for(ll i = 1; i < odd_degs.size(); i+=2){
    edges++;
    adj[odd_degs[i-1]].pb(odd_degs[i]);
    deg[odd_degs[i-1]]++;
    adj[odd_degs[i]].pb(odd_degs[i-1]);
    deg[odd_degs[i]]++;
    idx[odd_degs[i-1]].pb(adj[odd_degs[i]].size()-1);
    idx[odd_degs[i]].pb(adj[odd_degs[i-1]].size()-1);
  }
  if(edges&1){
    edges++;
    adj[1].pb(1);
    deg[1]++;
    idx[1].pb(adj[1].size()-1);
  }
  // cout << "adj:\n";
  // for(ll i = 0; i < n+1; i++){
  //   cout << i << " -> ";
  //   for(auto el : adj[i]) cout << el << " ";
  //   cout << endl;
  // }
  // cout << endl;
  // cout << "idx\n";
  // for(ll i = 0; i < n+1; i++){
  //   cout << i << " -> ";
  //   for(auto el : idx[i]) cout << el << " ";
  //   cout << endl;
  // }
  // cout << endl;
  for(ll i = 1; i <= n; i++) vis[i].assign((ll)adj[i].size(), false);
  vector<ll> euler;
  dfs(1,adj,vis,idx,euler);
  // for(auto el : euler) cout << el << " ";
  // cout << endl;
  cout << edges << endl;
  for(ll i = 1; i < euler.size(); i++){
    if(i&1) cout << euler[i-1] << " " << euler[i] << endl;  
    else cout << euler[i] << " " << euler[i-1] << endl;
  }
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}