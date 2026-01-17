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
const int maxn = 2e5+1;
vector<int> adj[maxn];
bool vis[maxn];
int dist[maxn];

void dfs(int u, int p){
  if(p != -1) dist[u] = dist[p]+1;
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) dfs(v,u);
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,-1);
  int mx = 1;
  for(int i = 1; i <= n; i++){
    if(dist[mx] < dist[i]) mx = i;
  }
  for(int i = 1; i <= n; i++){
    vis[i] = false;
    dist[i] = 0;
  }
  dfs(mx, -1);
  mx = 0;
  for(int i = 1; i <= n; i++){
    mx = max(mx, dist[i]);
  }
  cout << mx << endl;
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}