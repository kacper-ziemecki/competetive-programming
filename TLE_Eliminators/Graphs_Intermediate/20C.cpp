#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m; 
ll u,v,w,d;
const ll N = 1e5+1;
vector<pair<ll,ll>> adj[N];
ll dist[N],parent[N];

void solve(){
  cin >> n >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  for(ll i = 2; i <= n; i++) dist[i] = LLONG_MAX;
  dist[1] = 0;
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
  pq.emplace(make_pair(0,1));
  parent[1] = 1;
  while(!pq.empty()){
    u = pq.top().second;
    d = pq.top().first;
    // dbg(u, dist[u]);
    pq.pop();
    if(d != dist[u]) continue;
    for(auto edges : adj[u]){
      v = edges.first;
      w = edges.second;
      if(dist[v] > d+w){
        dist[v] = d+w;
        parent[v] = u;
        pq.emplace(make_pair(dist[v], v));
      }
    }
  }
  vector<ll> res;
  ll u = n;
  // for(int i = 1; i <= n; i++) cout << parent[i] << ' ';
  // cout << endl;
  while(true){
    res.pb(u);
    if(u == parent[u]) break;
    u = parent[u];
  }
  reverse(res.begin(), res.end());
  // for(auto el : res) cout << el << ' ';
  // cout << endl;
  if(res[0] != 1){
    cout << -1 << endl;
  } else{
    for(auto el : res) cout << el << ' ';
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

  
  solve();
}