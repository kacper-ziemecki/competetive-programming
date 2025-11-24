#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
void compare(vector<bool> &vis, vector<bool> &res){
  for(ll i = 0; i < res.size(); i++) res[i] = vis[i] & res[i];
}

void dfs(ll u, vector<vector<ll>>& adj, vector<bool> &vis, vector<vector<bool>> & res){
  vis[u] = true;
  compare(vis, res[u]);
  for(auto v : adj[u]){
    if(!vis[v]) dfs(v, adj, vis, res);
  }
  vis[u] = false;
}

void solve(){
  ll n;
  cin >> n;
  vector<vector<ll>> list(n, vector<ll>(n)), adj(n);
  vector<vector<bool>> res(n, vector<bool>(n, true));
  vector<bool> vis(n, false);
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      cin >> list[i][j];
      if(list[i][j]) adj[i].push_back(j);
    }
  }
  dfs(0, adj, vis, res);
  for(ll i = 0; i < n; i++){
    cout << "+";
    for(ll j = 0; j < 2*n-1; j++) cout << "-";
    cout << "+\n";
    cout << "|";
    for(ll j = 0; j < n; j++){
      cout << (res[j][i] ? "Y" : "N") << "|";
    }
    cout << endl;
  }
  cout << "+";
  for(ll j = 0; j < 2*n-1; j++) cout << "-";
  cout << "+\n";
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
  for(ll i = 1; i <= t; i++){
    cout << "Case " << i << ":\n";
    solve();
  }
}