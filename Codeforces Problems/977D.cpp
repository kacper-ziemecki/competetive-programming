#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool dfs(ll u, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& res, ll cnt=0){
  vis[u] = true;
  cnt++;
  if(cnt == vis.size()){
    res.push_back(u);
    return true;
  }
  for(auto v : adj[u]){
    if(!vis[v] && dfs(v, adj, vis, res, cnt)){
      res.push_back(u);
      return true;
    }
  }
  return false;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n),indeg(n, 0);
  vector<bool> vis(n, false);
  vector<vector<ll>> adj(n);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(i==j) continue;
      if(list[i]*2 == list[j]){
        adj[i].push_back(j);
        indeg[j]++;
      }
      if(list[j]*3 == list[i]){
        adj[i].push_back(j);
        indeg[j]++;
      }
    }
  }
  vector<ll> res;
  for(ll i = 0; i < n; i++){
    if(indeg[i]==0){
      dfs(i, adj, vis, res);
      break;
    }
  }
  reverse(res.begin(), res.end());
  for(auto el : res) cout << list[el] << " ";
  cout << endl;
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