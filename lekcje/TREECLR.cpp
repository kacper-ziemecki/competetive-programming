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


ll dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& computed, ll c){
  vis[u] = true;
  ll res = c;
  for(auto v : adj[u]) if(vis[v]) res -= computed[v]+1;

  for(auto v : adj[u]){
    if(!vis[v]){
      computed[v]++;
      res *= dfs(v,adj,vis,computed,c);
      computed[u]++;
    }
    res %= (ll)1e9+7;
  }
  return res;
}

void solve()
{
  ll n,c,u,v;
  cin >> n >> c;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1,false);
  vector<ll> computed(n+1, 0);
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << dfs(1,adj,vis,computed,c) << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}