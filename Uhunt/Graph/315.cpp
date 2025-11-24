#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<vector<ll>> adj;
vector<ll> dfs_num,dfs_low,articulation_vertex,dfs_parent;
ll root,rootChildren,cnt;

void dfs(ll u){
  dfs_num[u] = dfs_low[u] = cnt++;
  for(auto v : adj[u]){
    if(dfs_num[v] == -1){
      dfs_parent[v] = u;
      if(u == root) rootChildren++;
      dfs(v);

      if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u]=1;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
  // dbg(u, dfs_num[u], dfs_low[u]);
}

void solve(){
 ll n;
 cin >> n;
 if(n == 0) return;
 dfs_num.assign(n+1, -1);
 dfs_low.assign(n+1, -1);
 articulation_vertex.assign(n+1, 0);
 dfs_parent.assign(n+1, -1);
 adj.assign(n+1, vector<ll>());
 string s;
 while(getline(cin >> ws, s), s[0] != '0'){
  stringstream stream;
  stream << s;
  ll u,v;
  stream >> u;
  while(!stream.eof()){
    stream >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 }
 for(ll i = 1; i <= n; i++){
  if(dfs_num[i] == -1){
    root = i;
    rootChildren = 0;
    cnt = 0;
    dfs(i);
    articulation_vertex[i]=(rootChildren>1);
  }
 }
 ll res=0;
 for(auto el : articulation_vertex) if(el) res++;
  cout << res << endl;
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

  while(!cin.eof()){
    solve();
  }

}