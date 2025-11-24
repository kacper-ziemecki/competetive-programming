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

pair<ll,ll> dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, string& color, ll& res){
  pair<ll,ll> colors = {0,0};
  if(color[u-1] == 'W') colors.first++;
  else colors.second++;
  vis[u]=true;
  for(auto v : adj[u]){
    if(!vis[v]){
      pair<ll,ll> tmp = dfs(v,adj,vis,color,res);
      colors = {colors.first + tmp.first, colors.second + tmp.second};
    }
  }
  if(colors.first == colors.second) res++;
  return colors;
}

void solve()
{
  ll n,u;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1, false);
  for(ll v = 2; v <= n; v++){
    cin >> u;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  string color;
  cin >> color;
  ll res=0;
  dfs(1,adj,vis,color,res);
  cout << res << endl;
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