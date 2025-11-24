#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll l, ll u, ll r, ll t){
  vector<ll> list(r);
  string s;
  vector<vector<ll>> adj(10000);
  vector<bool> vis(10000);
  vector<ll> dist(10000);
  queue<ll> q;
  for(ll i = 0; i < r; i++){
    cin >> s;
    list[i] = stoll(s);
  }
  for(ll i = 0; i <= 9999; i++){
    for(auto el : list){
      adj[i].push_back((i+el)%10000);
    }
  }

  q.push(l);
  vis[l]=true;
  dist[l]=0;
  while(!q.empty()){
    ll u = q.front(); q.pop();
    for(auto v : adj[u]){
      if(!vis[v]){
        vis[v]=true;
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
  cout << "Case " << t << ": ";
  if(!vis[u]) cout << "Permanently Locked\n";
  else cout << dist[u] << endl;
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

  ll l,u,r;
  ll i=0;
  while(cin>>l>>u>>r,l!=0||u!=0||r!=0) solve(l,u,r,++i);
}