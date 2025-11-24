#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,u,v;
  cin >> n;
  vector<vector<ll>> adj(n+1);
  vector<ll> dist(n+1), deg(n+1, 0);
  vector<ld> probability(n+1);
  vector<bool> vis(n+1, false);
  queue<ll> q;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++; deg[v]++;
  }

  q.push(1);
  vis[1] = true;
  dist[1] = 0;
  probability[1] = 1;
  while(!q.empty()){
    u = q.front(); q.pop();
    for(auto v : adj[u]){
      if(!vis[v]){
        q.push(v);
        vis[v] = true;
        dist[v] = dist[u]+1;
        probability[v] = (ld)(probability[u] / (ld)(u == 1 ? adj[u].size() : adj[u].size()-1));
      }
    }
  }
  // for(auto el : probability) cout << el << " ";
  // cout << endl;
  ld res = 0;
  for(ll i = 1; i < n+1; i++){
    if(deg[i] == 1) res += (ld)(probability[i] * dist[i]);
  }
  cout << fixed << setprecision(7) << res << endl;
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