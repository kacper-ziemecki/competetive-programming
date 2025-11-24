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

void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, map<pair<ll,ll>, ll>& mp, vector<ll>& res, ll prev=2){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]){
      if(prev==2){
        res[mp[{u,v}]] = 3;
        dfs(v,adj,vis,mp,res,3);
        prev=3;
      } else{
        res[mp[{u,v}]] = 2;
        dfs(v,adj,vis,mp,res,2);
        prev=2;
      }
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  map<pair<ll,ll>, ll> mp;
  vector<bool> vis(n+1);
  vector<ll> deg(n+1), res(n-1);
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    mp[{u,v}] = i;
    mp[{v,u}] = i;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++; deg[v]++;
  }
  for(auto el : deg){
    if(el > 2){
      cout << -1 << endl; return;
    }
  }
  dfs(1, adj, vis, mp, res);
  for(auto el : res) cout << el << " ";
  cout << endl;
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