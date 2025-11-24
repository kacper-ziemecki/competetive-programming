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

vector<vector<ll>> adj,dp;
vector<ll> preorder, postorder;
ll timer = 0;
ll l;
void dfs(ll u, ll p){
  preorder[u] = ++timer;
  dp[u][0] = p;
  for(ll i = 1; i <= l; i++){
    dp[u][i] = dp[dp[u][i-1]][i-1];
  }

  for(auto v : adj[u]){
    if(v == p) continue;
    dfs(v,u);
  }
  postorder[u] = ++timer;
}

bool is_ancestor(ll up, ll down){
  return (preorder[up] <= preorder[down] && postorder[up] >= postorder[down]);
}

ll lca(ll a, ll b){
  if(is_ancestor(a,b)) return a;
  if(is_ancestor(b,a)) return b;
  for(ll i = l; i >= 0; i--){
    while(!is_ancestor(dp[a][i], b)){
      a = dp[a][i];
    }
  }
  return dp[a][0];
}

void solve()
{
  ll n,k,z,u,v;
  cin >> n >> k >> z;
  l = min((ll)ceil(log2(n)), 6ll);
  adj.resize(n+1);
  preorder.resize(n+1);
  postorder.resize(n+1);
  dp.assign(n+1, vector<ll>(l+1));
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(k,k);


  for(ll i = 0; i < z; i++){
    cin >> u >> v;
    cout << lca(u,v) << endl;
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}