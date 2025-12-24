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

int n,m;
int u,v;
int cnt;
const int maxn = 5e4+1;
vector<int> adj[maxn], adj_t[maxn], adj_scc[maxn];
bool vis[maxn];
int indeg[maxn], subtree[maxn];
vector<int> order;

struct DSU{
  vector<int> p,sajz;
  DSU(int n){
    p.resize(n+1);
    sajz.assign(n+1, 1);
    for(int i = 0; i <= n; i++) p[i] = i;
  } 
  int getSet(int a){return (p[a] == a ? a : p[a] = getSet(p[a]));}
  void unionSet(int a, int b){
    a = getSet(a);
    b = getSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a, b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
};

void dfs1(int u){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) dfs1(v);
  }
  order.pb(u);
}

void dfs2(int u, int prev, DSU &dsu){
  dsu.unionSet(u,prev);
  vis[u] = true;
  for(auto v : adj_t[u]){
    if(!vis[v]) dfs2(v,u,dsu);
  }
}

int calc_subtree(int u, DSU &dsu){
  subtree[u] = dsu.sajz[u];
  for(auto v : adj_scc[u]){
    subtree[u] += calc_subtree(v,dsu);
  }
  return subtree[u];
}

void solve(){
  cin >> n >> m;
  DSU dsu(n+1);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj_t[v].pb(u);
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs1(i);
  }
  reverse(order.begin(), order.end());

  for(int i = 1; i <= n; i++) vis[i] = false;
  for(auto el : order){
    if(!vis[el]) dfs2(el, el, dsu);
  }
  for(int i = 1; i <= n; i++){
    for(auto v : adj[i]){
      if(dsu.getSet(i) == dsu.getSet(v)) continue;
      adj_scc[dsu.getSet(i)].pb(dsu.getSet(v));
    }
  }
  for(int i = 1; i <= n; i++){
    for(auto v : adj_scc[i]){
      indeg[v]++;
    }
  }
  for(int i = 1; i <= n; i++){
    if(indeg[i] == 0){
      calc_subtree(i, dsu);
    }
  }
  for(int i = 1; i <= n; i++){
    cout << subtree[dsu.getSet(i)]-1 << endl;
  }
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