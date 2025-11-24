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
  ll n,m,s,t;
  cin >> n >> m >> s >> t;
  vector<vector<pair<ll,ll>>> adj(n);
  vector<ll> dist(n, LLONG_MAX);
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
  dist[s]=0;
  pq.emplace(0, s);
  while(!pq.empty()){
    auto [w1, u] = pq.top(); pq.pop();
    for(auto [w2, v] : adj[u]){
      if(dist[v] > w1+w2){
        dist[v] = w1+w2;
        pq.emplace(dist[v], v);
      }
    }
  }
  if(dist[t] == LLONG_MAX) cout << "unreachable\n";
  else cout << dist[t] << endl;
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
    cout << "Case #" << i << ": ";
    solve();
  }
}