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
    if(!vis[v] && color[u-1] != color[v-1]){
      res = {u,v};
    } else if(!vis[v]) dfs1(v);
  }
}
bool same(int u, int c){
  // dbg(u, c);
  vis[u] = true;
  if(color[u-1] != c) return false;
  for(auto v : adj[u]){
    if(!vis[v] && !same(v, c)) return false;
  }
  return true;
}

bool check(int u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!same(v, color[v-1])) return false;
  }
  return true;
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
  // dbg(res.first, res.second);
  for(int i = 1; i <= n; i++) vis[i] = false;
  if(check(res.first)){
    cout << "YES\n";
    cout << res.first << endl;
    return;
  }
  // cout << "-------------\n";
  for(int i = 1; i <= n; i++) vis[i] = false; 
  if(check(res.second)){
    cout << "YES\n";
    cout << res.second << endl;
  } else{
    cout << "NO\n";
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