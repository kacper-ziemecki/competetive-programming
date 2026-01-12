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

int n;
int u,v;
const int maxn = 1e5+1;
vector<int> adj[maxn];
int color[maxn], deg[maxn];
bool vis[maxn];
pair<int,int> res = {1,2};

void dfs1(int u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v] && color[u] != color[v]){
      res = {u,v};
    } else if(!vis[v]) dfs1(v);
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(int i = 0; i < n; i++) cin >> color[i];
  dfs1(1);
  dbg(res.first, res.second);
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