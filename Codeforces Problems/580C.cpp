#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll dfs(ll u, vector<vector<ll>> &adj, vector<bool>& vis, vector<ll>& cat, ll n, ll m, ll cnt=0){
  // dbg(u);
  vis[u] = true;
  if(cat[u]) cnt++;
  else cnt=0;
  // dbg(u, cnt);
  if(cnt > m) return 0;
  if(adj[u].size()==1 && vis[adj[u][0]]) return 1;
  ll res=0;
  for(auto v : adj[u]){
    if(!vis[v]) res += dfs(v,adj,vis,cat,n,m,cnt);
  }
  return res;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<bool> vis(n);
  vector<ll> cat(n);
  for(auto &el : cat) cin >> el;
  vector<vector<ll>> adj(n);
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // for(ll i = 0; i < n; i++){
  //   cout << i << " -> ";
  //   for(auto el : adj[i]) cout << el << " ";
  //   cout << endl;
  // }
  cout << dfs(0, adj, vis, cat, n, m) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
  
}