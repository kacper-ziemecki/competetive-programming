#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll dfs(ll u, vector<stack<ll>>& p, map<pair<ll,ll>, ll>& length){
  ll res = 0;
  while(!p[u].empty()){
    ll v = p[u].top(); p[u].pop();
    // dbg(u, v, length[{u,v}]);
    res += length[{u, v}];
    res += dfs(v, p, length);
  }
  return res;
}

void solve(){
  ll n,m;
  cin >> n >> m;
  if(cin.eof()) return;
  vector<vector<pair<ll,ll>>> adj(n);
  map<pair<ll,ll>, ll> length;
  vector<stack<ll>> p(n);
  vector<ll> dist(n, LLONG_MAX);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
  dist[0]=0;
  pq.emplace(0,0);
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});

    if(length.count({u,v}) == 0) length[{u,v}] = w;
    else length[{u,v}] = min(length[{u,v}], w);

    if(length.count({v,u}) == 0) length[{v,u}] = w;
    else length[{v,u}] = min(length[{v,u}], w);
  }
  while(!pq.empty()){
    auto [w1, u] = pq.top(); pq.pop();
    for(auto [w2, v] : adj[u]){
      if(dist[v] == w1+w2){
        p[v].push(u);
      }
      else if(dist[v] > w1+w2){
        dist[v]=w1+w2;
        while(!p[v].empty()) p[v].pop();
        p[v].push(u);
        pq.emplace(dist[v], v);
      }
    }
  }
  ll res = dfs(n-1, p, length);
  cout << 2*res << endl;
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

  while(!cin.eof()) solve();

}