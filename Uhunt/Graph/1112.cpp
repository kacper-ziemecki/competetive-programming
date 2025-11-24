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
  ll n,e,f,m;
  cin >> n >> e >> f >> m;
  vector<vector<pair<ll,ll>>> adj(n+1);
  vector<ll> dist(n+1, LLONG_MAX);
  dist[e]=0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
  pq.emplace(0, e);
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }
  while(!pq.empty()){
    auto [w1, u] = pq.top(); pq.pop();
    for(auto [w2, v] : adj[u]){
      if(dist[v] > w1+w2){
        dist[v] = w1+w2;
        pq.emplace(dist[v], v);
      }
    }
  }
  ll res=0;
  for(auto el : dist){
    if(el <= f) res++;
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
  for(ll i = 1; i <= t; i++){
    solve();
    if(i != t) cout << endl;
  }
}