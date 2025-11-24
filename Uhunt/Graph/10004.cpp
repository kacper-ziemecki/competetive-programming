#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool dfs(ll u, vector<vector<ll>>& adj, vector<ll>& vis){
  for(auto v : adj[u]){
    if(vis[v] == vis[u]) return false;
    if(vis[v] == -1){
      vis[v] = 1-vis[u];
      if(!dfs(v, adj, vis)) return false;
    }
  }
  return true;
}

void solve(ll n){
  ll l;
  cin >> l;
  vector<vector<ll>> adj(n);
  vector<ll> vis(n, -1);
  ll u,v;
  for(ll i = 0; i < l; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 
  vis[0] = 0;
  cout << (dfs(0, adj, vis) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  ll n;
  while(cin >> n, n != 0) solve(n);
}