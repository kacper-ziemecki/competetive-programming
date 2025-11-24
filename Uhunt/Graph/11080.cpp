#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


pair<ll,ll> dfs(ll u, vector<vector<ll>> &adj, vector<ll> &vis){
  pair<ll,ll> res{0,0};
  if(vis[u] == 1) res.first++;
  else if(vis[u] == 0) res.second++;
  for(auto v : adj[u]){
    if(vis[v] == vis[u]) return {-1,-1};
    else if(vis[v] == -1){
      vis[v] = 1-vis[u];
      pair<ll,ll> tmp = dfs(v,adj,vis);
      if(tmp.first == -1) return {-1,-1};
      res = {res.first+tmp.first,res.second+tmp.second};
    }
  }
  return res;
}

void solve(){
  ll n,m,res=0;
  cin >> n >> m;
  vector<vector<ll>> adj(n);
  vector<ll> vis(n, -1);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(ll i = 0; i < n; i++){
    if(vis[i] == -1){
      vis[i] = 0;
      pair<ll,ll> cnt = dfs(i, adj, vis);
      if(cnt.first != -1){
        if(cnt.first == 0 || cnt.second == 0) res += max(cnt.first,cnt.second);
        else res += min(cnt.first,cnt.second);
      }
      else{
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << res << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}