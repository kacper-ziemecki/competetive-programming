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
  vector<vector<ll>> adj(n);
  vector<ll> dist(n);
  vector<bool> vis(n);
  queue<ll> q;
  dist[0]=0;
  vis[0]=true;
  q.push(0);
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  while(!q.empty()){
    u = q.front(); q.pop();
    for(auto v : adj[u]){
      if(!vis[v]){
        vis[v]=true;
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
  for(ll i = 1; i < n; i++) cout << dist[i] << endl;
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
  for(ll i = 0; i < t; i++){
    if(i!=0)cout << endl;
    solve();
  }
}