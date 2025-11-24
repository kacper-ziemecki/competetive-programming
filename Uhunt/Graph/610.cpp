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
vector<ll> dfs_num, dfs_low, dfs_parent;
map<pair<ll,ll>,bool> res;
vector<pair<ll,ll>> answer;
map<pair<ll,ll>,bool> vis;
ll dfsCnt;

void dfs(ll u){
  dfs_num[u] = dfs_low[u] = ++dfsCnt;
  for(ll v : adj[u]){
    if(!dfs_num[v]){
      dfs_parent[v] = u;
      dfs(v);
      if(dfs_low[v] > dfs_num[u]) res[{u, v}]=true;
      // dbg(u,v, dfs_num[u], dfs_low[v]);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void direction(ll u){
  for(ll v : adj[u]){
    if(vis.count({min(u,v), max(u,v)}) == 0){
      vis[{min(u,v), max(u,v)}]=true;
      answer.push_back({u, v});
      direction(v);
    }
  }
}
void solve(ll n, ll m){
  adj.assign(n+1, vector<ll>());
  dfs_num.assign(n+1, 0);
  dfs_low.assign(n+1, 0);
  dfs_parent.assign(n+1, 0);
  res.clear();
  vis.clear();
  answer.clear();
  ll u,v;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfsCnt=0;
  dfs(1);
    

  direction(1);
  
  // cout << "res:\n";
  // for(auto el : res){
  //   cout << el.first.first << " " << el.first.second << endl;
  // }
  // cout << "parent:\n";
  // for(auto el : dfs_parent) cout << el << " ";
  // cout << endl;
  // cout << "----\n";
  for(auto el : answer){
    // dbg(el.first, el.second); 
    if(!res[{el.first, el.second}] && !res[{el.second, el.first}]){
      cout << el.first << " " << el.second << endl; 
    } else{
      cout << el.first << " " << el.second << endl; 
      cout << el.second << " " << el.first << endl; 
    }
  }
  cout << "#\n";
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

  ll n,m,t=0;
  while(cin >> n >> m, n != 0 || m != 0){
    cout << ++t << endl << endl;
    solve(n,m);
  }
}