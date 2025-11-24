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

const ll maxN = 2e5+1;
ll res=0;
vector<ll> adj[maxN];
ll dp[maxN];
bool children_are_leafs_or_leaf[maxN];

ll dfs(ll u, ll p){
  ll children = 0;
  ll leafs = 0;
  bool is_leaf = true;
  pair<ll,ll> mx1={0,0},mx2={0,0};
  for(auto v : adj[u]){
    if(v == p) continue;
    if(adj[v].size() == 1) leafs++;
    children++;
    is_leaf = false;
    ll tmp = dfs(v,u);
    if(tmp+children_are_leafs_or_leaf[v] >= mx1.first){
      mx2 = mx1;
      mx1 = {tmp+children_are_leafs_or_leaf[v], v};
    } else if(tmp+children_are_leafs_or_leaf[v] > mx2.first){
      mx2 = {tmp+children_are_leafs_or_leaf[v], v};
    }
  }
  // dbg(u, is_leaf);
  if(is_leaf){
    children_are_leafs_or_leaf[u] = true;
    return dp[u] = 0;
  }
  if(leafs >= (ll)adj[u].size()-1) children_are_leafs_or_leaf[u] = true;

  dp[u] = (adj[u].size()-1) + (mx1.first-1);

  if(children > 1){
    res = max(res, (ll)((mx1.first-1)+(mx2.first-1)+adj[u].size()-2));
  }
  res = max(res, dp[u]);
  return dp[u];
}

void solve()
{
  ll n,u,v;
  cin >> n;
  for(ll i = 1; i < n; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, 1);
  cout << res << endl;
  for(ll i = 1; i <= n; i++) children_are_leafs_or_leaf[i] = false;

  for(ll u = 1; u <= n; u++) dbg(u, dp[u]);
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}