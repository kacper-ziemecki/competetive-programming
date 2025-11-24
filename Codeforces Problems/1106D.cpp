#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+1, false);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<ll> res;
  priority_queue<ll> pq;
  vis[1] = true;
  pq.push(-1);
  while(!pq.empty()){
    u = pq.top(); pq.pop();
    res.push_back(-u);
    for(auto v : adj[-u]){
      if(!vis[v]){
        vis[v] = true;
        pq.push(-v);
      }
    }
  }
  for(auto el : res) cout << el << " ";
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