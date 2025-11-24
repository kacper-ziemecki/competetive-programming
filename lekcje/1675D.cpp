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

void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& res){
  vis[u] = true; 
  res.pb(u);
  for(auto v : adj[u]){
    if(!vis[v]){
      dfs(v,adj,vis,res);
      break;
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  ll root;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1, false);
  vector<ll> vertices;
  ll a;
  for(ll i = 1; i <= n; i++){
    cin >> a;
    if(a == i) root = a;
    else{
      adj[i].pb(a);
      adj[a].pb(i);
    }
  }
  queue<ll> q;
  q.emplace(root);
  vis[root] = true;
  while(!q.empty()){
    ll u = q.front(); q.pop();
    vertices.pb(u);
    for(auto v : adj[u]){
      if(!vis[v]){
        q.emplace(v);
        vis[v] = true;
      }
    }
  }
  vis.assign(n+1, false);
  vector<vector<ll>> res;
  for(auto u : vertices){
    vector<ll> tmp;
    if(!vis[u]){
      dfs(u, adj, vis, tmp);
      res.pb(tmp);
    }
  }
  cout << res.size() << endl;
  for(auto sub : res){
    cout << sub.size() << endl;
    for(auto el : sub) cout << el << " ";
    cout << endl;
  }
  cout << endl;
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