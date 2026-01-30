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

int n,m;
ll INF = 1e16;
ll u,v,w,d;
ll res=INF;
const int N = 1e5+1;
vector<pair<int,ll>> adj[N], adj_T[N];
ll dist_to_source[N], dist_to_destination[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;


void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj_T[v].pb(make_pair(u,w));
  }
  for(int i = 1; i <= n; i++){
    dist_to_source[i] = INF;
    dist_to_destination[i] = INF;
  }
  dist_to_source[1] = 0;
  pq.emplace(make_pair(0,1));
  while(!pq.empty()){
    u = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(dist_to_source[u] < d) continue;
    for(auto edge : adj[u]){
      v = edge.first;
      w = edge.second;
      if(dist_to_source[v] > d+w){
        dist_to_source[v] = d+w;
        pq.emplace(make_pair(dist_to_source[v], v));
      }
    }
  }

  dist_to_destination[n] = 0;
  pq.emplace(make_pair(0,n));
  while(!pq.empty()){
    u = pq.top().second;
    d = pq.top().first;
    pq.pop();
    if(dist_to_destination[u] < d) continue;
    for(auto edge : adj_T[u]){
      v = edge.first;
      w = edge.second;
      if(dist_to_destination[v] > d+w){
        dist_to_destination[v] = d+w;
        pq.emplace(make_pair(dist_to_destination[v],v));
      }
    }
  }

  for(int u = 1; u <= n; u++){
    for(auto edge : adj[u]){
      v = edge.first;
      w = edge.second;
      // dbg(u,v);
      // dbg(w, dist_to_source[u], dist_to_destination[v]);
      res = min(res, dist_to_source[u]+(w/2)+dist_to_destination[v]);
    }
  }
  cout << res << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}