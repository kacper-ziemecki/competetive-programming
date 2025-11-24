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

void dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& cur, vector<ll>& goal, vector<ll>& res, ll dist=0, ll odd=0, ll even=0){
  vis[u] = true;
  if((cur[u-1]+(dist&1 ? odd : even)) % 2 != goal[u-1]){
    res.pb(u);
    if(dist&1) odd++;
    else even++;
  }
  for(auto v : adj[u]){
    if(!vis[v]){
      dfs(v,adj,vis,cur,goal,res,dist+1,odd,even);
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1);
  vector<ll> cur(n), goal(n);
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(auto& el : cur) cin >> el;
  for(auto& el : goal) cin >> el;
  vector<ll> res;
  dfs(1, adj, vis, cur, goal, res);
  cout << res.size() << endl;
  for(auto el : res) cout << el << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}