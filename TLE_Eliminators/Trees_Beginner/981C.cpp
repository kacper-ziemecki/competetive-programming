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

int n,cnt=0,root=1;
int u,v;
const int maxn = 1e5+1;
vector<int> adj[maxn];
int deg[maxn];
vector<vector<pair<int,int>>> res;
set<pair<int,int>> vis;

void dfs(int u){
  for(auto v : adj[u]){
    // dbg(u,v,vis.count(make_pair(max(u,v), min(u,v))));
    if(vis.count(make_pair(max(u,v), min(u,v))) == 0){
      if(u == root) res.pb({});
      vis.emplace(make_pair(max(u,v), min(u,v)));
      res.back().pb(make_pair(u,v));
      dfs(v);
    }
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    deg[u]++;
    deg[v]++;
  }
  for(int i = 1; i <= n; i++){
    if(deg[i] > 2){
      cnt++;
      root = i;
    }
  }
  if(cnt > 1){
    cout << "No\n";
    return;
  }
  while(vis.size() < n-1){
    // for(auto el : vis) cout << el.first << ' ' << el.second << endl;
    // cout << "--------\n";
    dfs(root);
  }
  cout << "Yes\n";
  cout << res.size() << endl;
  for(auto sub : res){
    cout << sub.front().first << ' ' << sub.back().second << endl;
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

  solve();
}