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

const ll maxN = 5*1e5+1;
const ll l = ceil(log2(maxN));
vector<pair<ll,ll>> adj[maxN];
ll dist[maxN],preorder[maxN], postorder[maxN];
ll dp[maxN][l+1];
ll timer=0;

void dfs(ll u, ll p){
  preorder[u] = ++timer;
  dp[u][0] = p;
  for(ll i = 1; i <= l; i++) dp[u][i] = dp[dp[u][i-1]][i-1];
  for(auto [v,w] : adj[u]){
    if(v == p) continue;
    dist[v] = dist[u]+w;
    dfs(v,u);
  }
  postorder[u] = timer;
}

bool is_ancestor(ll up, ll down){
  return (preorder[up] <= preorder[down] && postorder[up] >= postorder[down]);
}

ll lca(ll u, ll v){
  if(is_ancestor(u,v)) return u;
  if(is_ancestor(v,u)) return v;

  for(ll i = l; i >= 0; i--){
    if(!is_ancestor(dp[u][i], v)) u = dp[u][i];
  }
  return dp[u][0];
}

void solve()
{
  ll n,q,u,v,w;
  cin >> n >> q;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v >> w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }
  dist[1] = 0;
  dfs(1,1);

  // for(ll u = 1; u <= n; u++) cout << dist[u] << " ";
  // cout << endl << endl;
  
  // for(ll u = 1; u <= n; u++){
  //   for(ll i = 0; i < 4; i++) cout << dp[u][i] << " ";
  //   cout << endl;
  // }
  // cout << endl;

  for(ll i = 0; i < q; i++){
    cin >> u >> v;
    // dbg(dist[u], dist[v], lca(u,v));
    cout << dist[u]+dist[v]-2*dist[lca(u,v)] << endl;
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}