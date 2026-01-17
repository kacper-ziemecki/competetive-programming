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


int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  int u,v,w;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  queue<int> q;
  q.push(1);
  vector<bool> vis(n+1, false);
  vis[1] = true;
  while(!q.empty()){
    u = q.front(); 
    q.pop();
    for(auto v : adj[u]){
      if(!vis[v.first]){
        vis[v.first] = true;
        q.push(v.first);
      }
    }
  }
}