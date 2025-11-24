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
  vector<vector<ll>> adj(2*max(m,n)+1);
  vector<bool> vis(2*max(m,n)+1,false);
  vector<ll> dist(2*max(m,n)+1,0);
  for(ll i = max(m,n)*2; i > 1; i--){
    if(!(i&1)) adj[i/2].push_back(i);
    adj[i].push_back(i-1);
  }
  queue<ll> q;
  q.push(n);
  vis[n]=true;
  while(!q.empty()){
    ll u = q.front(); q.pop();
    for(ll v : adj[u]){
      if(!vis[v]){
        vis[v]=true;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
  cout << dist[m] << endl;
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