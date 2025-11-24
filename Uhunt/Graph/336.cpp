#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll t=0;

void solve(ll n){
  map<ll,vector<ll>> adj;
  ll u,v;
  for(ll i = 0; i < n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while(cin>>u>>v, u!=0||v!=0){
    if(adj.count(u)==0){
      cout << "Case " << ++t << ": ";
      cout << adj.size() << " nodes not reachable from node " << u << " with TTL = " << v << "."<<endl;
      continue;
    }
    queue<ll> q;
    map<ll,ll> dist;
    map<ll,bool> vis;
    q.push(u);
    dist[u]=0;
    vis[u]=true;
    while(!q.empty()){
      ll p = q.front(); q.pop();
      for(ll c : adj[p]){
        if(!vis[c]){
          q.push(c);
          dist[c] = dist[p]+1;
          vis[c]=true;
        }
      }
    }
    ll res=0;
    for(auto el : adj){
      if(dist.count(el.first) == 0 || dist[el.first] > v){
        res++;
      }
    }
    cout << "Case " << ++t << ": ";
    cout << res << " nodes not reachable from node " << u << " with TTL = " << v << "."<<endl;
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

  ll n;
  while(cin>>n,n!=0){
    solve(n);
  }
}