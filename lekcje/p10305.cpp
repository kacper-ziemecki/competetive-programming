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


void solve(ll n, ll m)
{
  vector<vector<ll>> adj(n+1);
  vector<ll> in_deg(n+1);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    in_deg[v]++;
    adj[u].pb(v);
  }
  queue<ll> q;
  for(ll i = 1; i <= n; i++) if(!in_deg[i]) q.emplace(i);
  vector<ll> res;
  while(!q.empty()){
    u = q.front(); q.pop();
    res.pb(u);
    for(auto v : adj[u]){
      in_deg[v]--;
      if(in_deg[v] == 0) q.emplace(v);
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

  ll n,m;
  while(cin >> n >> m, n != 0 || m != 0) solve(n,m);
}