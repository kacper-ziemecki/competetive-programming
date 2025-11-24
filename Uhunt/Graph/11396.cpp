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
      if(!dfs(v,adj,vis)) return false;
    }
  }
  return true;
}

void solve(ll n){
  vector<vector<ll>> adj(n);
  vector<ll> vis(n, -1);
  ll u,v;
  while(cin >> u >> v, u != 0 || v != 0){
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(ll i = 0 ; i < n; i++){
    if(vis[i] == -1){
      vis[i] = 0;
      if(!dfs(i, adj, vis)){
        cout << "NO\n"; return;
      }
    }
  }
  cout << "YES\n";
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