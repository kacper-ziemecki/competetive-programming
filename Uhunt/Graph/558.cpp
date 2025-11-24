#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,m;
  cin >> n >> m;
  vector<vector<pair<ll,ll>>> adj(n);
  vector<ll> dist(n, LLONG_MAX);
  dist[0]=0;
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }
  bool modified;
  for(ll i = 0; i < n-1; i++){
    modified=false;
    for(ll u = 0; u < n; u++){
      if(dist[u] != LLONG_MAX){
        for(auto [v, w] : adj[u]){
          if(dist[v] < dist[u]+w) continue;
          dist[v] = dist[u]+w;
          modified=true;
        }
      }
    }
    if(!modified) break;
  }

  bool hasNegativeCycle=false;
  for(ll u = 0; u < n; u++){
    if(dist[u] != LLONG_MAX){
      for(auto [v, w] : adj[u]){
        if(dist[v] > dist[u]+w) hasNegativeCycle=true;
      }
    }
  }
  if(hasNegativeCycle) cout << "possible\n";
  else cout << "not possible\n";
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
  while(t--)
  solve();
  
}