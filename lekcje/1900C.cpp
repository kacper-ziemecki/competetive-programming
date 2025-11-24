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


ll dfs(ll u, vector<pair<ll,ll>>& adj, vector<bool>& vis, string& s){
  vis[u] = true;
  ll res = LLONG_MAX;
  if(adj[u].first){
    res = min(res, (s[u-1]!='L')+dfs(adj[u].first, adj, vis, s));
  }
  if(adj[u].second){
    res = min(res, (s[u-1]!='R')+dfs(adj[u].second, adj, vis, s));
  }
  if(res == LLONG_MAX) return 0;
  return res;
}

void solve()
{
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<ll,ll>> adj(n+1);
  vector<bool> vis(n+1);
  ll u,v;
  for(ll i = 1; i <= n; i++){
    cin >> u >> v;
    adj[i] = {u, v};
  }
  cout << dfs(1, adj, vis, s) << endl;
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