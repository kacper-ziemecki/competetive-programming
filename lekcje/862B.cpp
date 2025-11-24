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


void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& bipartite, ll& ones, ll& zeros){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]){
      bipartite[v] = 1-bipartite[u];
      if(bipartite[v] == 1) ones++;
      else zeros++;
      dfs(v,adj,vis,bipartite,ones,zeros);
    }
  }
}

void solve()
{
  ll n,u,v,ones=1,zeros=0,res=0;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1, false);
  vector<ll> bipartite(n+1, -1);
  bipartite[1] = 1;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, adj, vis, bipartite, ones, zeros);
  for(ll i = 1; i <= n; i++){
    if(bipartite[i]){
      res += zeros-adj[i].size();
    } else{
      res += ones-adj[i].size();
    }
  }
  cout << res/2 << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}