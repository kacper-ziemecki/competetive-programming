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

ll dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, map<pair<ll,ll>, ll>& order, ll p=-1){
  // dbg(u, p);
  vis[u] = true;
  ll res = 0;
  for(auto v : adj[u]){
    if(!vis[v]){
      res = max(res, (p>order[{u,v}] ? 1 : 0) + dfs(v,adj,vis,order, order[{u,v}]));
    }
  }
  // dbg(u, res);
  return res;
}

void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  map<pair<ll,ll>, ll> order;
  vector<bool> vis(n+1);
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    order[{u,v}] = i;
    order[{v,u}] = i;
  }
  cout << dfs(1, adj, vis, order)+1 << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while(t--){
    solve();
  }
}