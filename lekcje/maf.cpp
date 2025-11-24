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

const ll maxN = 1e6+1; 
ll cnt=1;
bool vis[maxN], coloring[maxN], has_black[maxN], done_scc[maxN];
ll in_deg[maxN], in_deg_scc[maxN], cast[maxN], size_of_scc[maxN];
vector<ll> adj[maxN], adj_t[maxN], adj_scc[maxN], topo;

void topo_sort(ll u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) topo_sort(v);
  }
  topo.pb(u);
}

void dfs(ll u){
  size_of_scc[cnt]++;
  vis[u] = true;
  cast[u] = cnt;
  for(auto v : adj_t[u]){
    if(!vis[v]) dfs(v);
  }
}

void dfsColor(ll u){
  vis[u] = true;
  for(ll v : adj[u]){
    if(!vis[v]){
      if(!coloring[v]) coloring[v] = !coloring[u];
      dfsColor(v);
    }
  }
}

void solve()
{
  ll n,u;
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> u;
    adj[i+1].pb(u);
    adj_t[u].pb(i+1);
    in_deg[u]++;
  }

  memset(vis, false, n+1);
  for(ll u = 1; u <= n; u++){
    if(!vis[u]) topo_sort(u);
  }
  reverse(topo.begin(), topo.end());


  memset(vis, false, n+1);
  for(auto u : topo){
    if(!vis[u]){
      dfs(u);
      cnt++;
    }
  }


  for(ll u = 1; u <= n; u++){
    for(auto v : adj[u]){
      if(cast[u] != cast[v]) adj_scc[cast[u]].pb(cast[v]);
    }
  }

  memset(in_deg_scc, 0, cnt);
  for(ll u = 1; u < cnt; u++){
    for(auto v : adj_scc[u]) in_deg_scc[v]++;
  }
  ll mx=0;
  for(ll u = 1; u < cnt; u++) mx += (size_of_scc[u]-1) + min(1ll, in_deg_scc[u]);
  
  memset(coloring, 0, n+1);
  memset(has_black, false, cnt);
  queue<ll> q;
  for(ll u = 1; u <= n; u++){
    if(size_of_scc[cast[u]] == 1 && in_deg[u] == 0){
      coloring[u] = 0;
      q.push(u);
    }
  }
  while(!q.empty()){
    u = q.front(); q.pop();
    if(size_of_scc[cast[u]] > 1) continue;
    for(ll v : adj[u]){
      if(!coloring[v]) coloring[v] = !coloring[u];
      if(coloring[v]) has_black[cast[v]] = true;
      in_deg[v]--;
      if(in_deg[v] == 0) q.push(v);
    }
  }
  memset(done_scc, false, cnt);
  memset(vis, false, n+1);
  for(ll u = 1; u <= n; u++){
    if((size_of_scc[cast[u]] > 1 && has_black[cast[u]] && coloring[u]==1 && !done_scc[cast[u]]) || (size_of_scc[cast[u]] > 1 && !has_black[cast[u]] && !done_scc[cast[u]])){
      dfsColor(u);
      done_scc[cast[u]] = true;
    }
  }
  ll mn = 0;
  for(ll u = 1; u <= n; u++){
    if(coloring[u]) mn++;
  }
  cout << mn << " " << mx << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}