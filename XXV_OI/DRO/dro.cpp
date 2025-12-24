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
vector<int> adj[maxn];
int indeg[maxn];
int subtree[maxn];
int vis[maxn];

struct DSU{
  vector<int> p,sajz;
  vector<bool> cycle;
  DSU(int n){
    p.resize(n+1);
    sajz.assign(n+1, 1);
    cycle.assign(n+1, false);
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

int dfs(int u){
  if(subtree[u] > 0) return subtree[u];
  subtree[u] = 1;
  for(auto v : adj[u]){
    subtree[u] += dfs(v);
  }
  return subtree[u];
}

bool vis1[maxn];
void cykl(int u){
  vis1[u] = true;
  cout << "-" << u;
  for(auto v : adj[u]){
    if(!vis1[v]) cykl(v);
  }
}

bool checkCycle(int u){
  vis[u] = 1;
  for(auto v : adj[u]){
    if(vis[v] == 1){ // mamy cykl
      vis[u] = -1;
      return true;
    } else if(vis[v] == 0 && checkCycle(v)){ //tez pozniej znajdziemy cykl
      vis[u] = -1;
      return true;
    }
  }
  vis[u] = -1; //stajemy sie staruchem
  return false;
}
void solve(){
  cin >> n >> m;
  DSU dsu(n+1);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    indeg[v]++;
    dsu.unionSet(u,v);
    adj[u].pb(v);
  }
  for(int i = 1; i <= n; i++) vis[i] = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i] == 0 && checkCycle(i)){
      dsu.cycle[dsu.getSet(i)] = true;
    }
  }
  for(int i = 1; i <= n; i++){
    if(!dsu.cycle[dsu.getSet(i)] && indeg[i] == 0) dfs(i);
  }
  for(int i = 1; i <= n; i++){
    if(dsu.cycle[dsu.getSet(i)]){
      cout << dsu.sajz[dsu.getSet(i)]-1;
      // cout << "-cykl:";
      // cout << "(" << dsu.getSet(i) <<"):";
      // for(int j = 0; j <= n; j++) vis1[j] = false;
      // cykl(i);
      // cout << "|";
      // for(int j = 1; j <= n; j++){
      //   if(dsu.getSet(j) == dsu.getSet(i)){
      //     cout << "(" << j << ")-";
      //     for(auto v : adj[j]) cout << "[" << v << "]";
      //   }
      // }
      cout << endl;
    } else{
      cout << subtree[i]-1 << endl;
      // cout << "-drzewo" << endl;
    }
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