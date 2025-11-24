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

void dfs(ll u, vector<vector<ll>>& adj, vector<unordered_map<ll,bool>>& vis, vector<ll>& order){
  for(auto v : adj[u]){
    if(!vis[u][v]){
      vis[u][v] = true;
      vis[v][u] = true;
      dfs(v,adj,vis,order);
    }
  }
  order.pb(u);
}

void solve()
{
  ll n,m,cnt=0;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
  vector<unordered_map<ll,bool>> vis(n+1);
  vector<ll> deg(n+1);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++; deg[v]++;
  }
  for(ll i = 1; i <= n; i++){
    if(deg[i]&1){
      adj[0].pb(i);
      adj[i].pb(0);
    } else cnt++;
  }
  vector<ll> order;
  for(ll i = 0; i <= n; i++){
    dfs(i, adj, vis, order);
    order.pb(0);
  }
  cout << cnt << endl;
  for(ll i = 1; i < order.size(); i++){
    if(order[i] != 0 && order[i-1] != 0){
      cout << order[i-1] << " " << order[i] << endl;
    }
  }
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}