#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


pair<bool, vector<ll>> check(vector<vector<pair<ll,ll>>>& adj, ll n, ll d, ll mid){
  vector<bool> vis(n+1, false);
  vector<ll> parent(n+1, -1), dist(n+1, LLONG_MAX);
  queue<ll> q;
  vis[1] = true;
  dist[1] = 0;
  q.push(1);
  while(!q.empty()){
    ll u = q.front(); q.pop();
    for(auto [v, w] : adj[u]){
      if(!vis[v] && w <= mid){
        dist[v] = dist[u]+1;
        vis[v] = true;
        q.push(v);
        parent[v] = u;
      }
    }
  }
  if(dist[n] <= d){
    vector<ll> res{n};
    ll c = n;
    while(c != 1){
      res.push_back(parent[c]);
      c = parent[c];
    }
    reverse(res.begin(), res.end());
    return {true, res};
  } else{
    return {false, {}};
  }
}

void solve()
{
  ll n,m,d;
  cin >> n >> m >> d;
  vector<vector<pair<ll,ll>>> adj(n+1);
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  ll l = 0, r = 1e10;
  vector<ll> ans;
  while(l < r){
    ll mid = (l+r)/2;
    pair<bool,vector<ll>> res = check(adj,n,d,mid);
    if(res.first){
      r = mid;
      ans = res.second;
    }
    else l = mid+1;
  }
  if(ans.empty()){
    cout << -1 << endl;
    return;
  }
  cout << ans.size()-1 << endl;
  for(auto el : ans) cout << el << " ";
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