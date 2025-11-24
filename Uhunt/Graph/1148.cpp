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
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n);
  vector<ll> dist(n);
  vector<bool> vis(n,false);
  queue<ll> q;
  ll m,u,v;
  for(ll i = 0; i < n; i++){
    cin >> u >> m;
    for(ll j = 0; j < m; j++){
      cin >> v;
      adj[u].push_back(v);
    }
  }
  cin >> u >> v;
  vis[u]=true;
  q.push(u);
  dist[u]=0;
  while(!q.empty()){
    ll p = q.front(); q.pop();
    for(auto c : adj[p]){
      if(!vis[c]){
        vis[c]=true;
        dist[c]=dist[p]+1;
        q.push(c);
      }
    }
  }
  cout << u << " " << v << " " << dist[v]-1 << endl;
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