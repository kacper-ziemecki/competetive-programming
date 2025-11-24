#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 

void dfs(ll u, vector<vector<ll>> &adj, vector<bool> &vis){
  for(auto v : adj[u]){
    if(!vis[v]){
      vis[v] = true;
      dfs(v, adj, vis);
    }
  }
}

void solve(ll n){
  ll v,u;
  vector<vector<ll>> adj(n+1);
  ll i = 0;
  while(cin >> v, v != 0){
    while(cin >> u, u != 0){
      adj[v].push_back(u);
    }
  }
  ll m;
  cin >> m;
  vector<ll> list(m), res;
  vector<bool> vis(n+1);
  for(auto &el : list) cin >> el;
  for(auto el : list){
    vis.assign(n+1, false);
    res.clear();
    dfs(el, adj, vis);
    for(ll i = 1; i < n+1; i++){
      if(!vis[i]) res.push_back(i);
    }
    cout << res.size();
    for(ll i = 0; i < res.size(); i++){
      cout << " " << res[i];
    }
    cout << endl;
  }
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
  while(cin >> n && n != 0){
    solve(n);
  }
}