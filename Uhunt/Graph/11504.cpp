#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
vector<unordered_set<ll>> adj,adj_inv,new_adj;

void dfs(ll u, vector<ll> &vis, vector<ll> &order, ll pass=1, ll color=1){
  vis[u] = color;
  unordered_set<ll> neighbors = (pass == 1 ? adj[u] : adj_inv[u]);
  for(auto v : neighbors){
    if(!vis[v]) dfs(v, vis, order, pass, color);
  }
  if(pass == 1) order.push_back(u);
}

void end_dfs(ll u, vector<ll> &vis){
  vis[u] = 1;
  for(auto v : new_adj[u]){
    if(!vis[v]) end_dfs(v, vis);
  }
}

void toposort(ll u, vector<ll> &vis, vector<ll> &topo){
  vis[u] = 1;
  for(auto v : new_adj[u]){
    if(!vis[v]) toposort(v, vis, topo);
  }
  topo.push_back(u);
}

void solve(){
  ll n,m,u,v;
  cin >> n >> m;
  adj.resize(n+1);
  adj_inv.resize(n+1);
  vector<ll> vis(n+1, 0);
  vector<ll> order;
  unordered_map<ll, vector<ll>> mp;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].emplace(v);
    adj_inv[v].emplace(u);
  }
  for(ll i = 1; i < n+1; i++){
    if(!vis[i]) dfs(i, vis, order);
  }
  ll cnt=1;
  vis.assign(n+1, 0);
  for(ll i = n-1; i >= 0; i--){
    if(!vis[order[i]]) dfs(order[i], vis, order, 2, cnt++);
  }
  new_adj.resize(cnt);
  for(ll i = 1; i < n+1; i++){
    mp[vis[i]].push_back(i);
  }
  for(auto el : mp){
    for(auto v : el.second){
      for(auto u : adj[v]) if(el.first != vis[u]) new_adj[el.first].emplace(vis[u]);
    }
  }
  vector<ll> topo;
  vis.assign(cnt, 0ll);
  for(ll i = 1; i < cnt; i++){
    if(!vis[i]) toposort(i, vis, topo);
  }
  reverse(topo.begin(), topo.end());
  vis.assign(cnt, 0);
  ll res = 0;
  for(auto u : topo){
    if(!vis[u]){ end_dfs(u, vis); res++; }
  }
  cout << res << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}