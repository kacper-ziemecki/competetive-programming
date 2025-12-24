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
    if(a == b){
      cycle[a] = true;
      return;
    }
    if(sajz[a] < sajz[b]) swap(a, b);
    p[b] = a;
    sajz[a] += sajz[b];
    cycle[a] = cycle[a] | cycle[b];
  }
};

int dfs(int u){
  subtree[u] = 1;
  for(auto v : adj[u]){
    subtree[u] += dfs(v);
  }
  return subtree[u];
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
  for(int i = 1; i <= n; i++){
    if(!dsu.cycle[dsu.getSet(i)] && indeg[i] == 0) dfs(i);
  }
  for(int i = 1; i <= n; i++){
    if(dsu.cycle[dsu.getSet(i)]){
      cout << dsu.sajz[dsu.getSet(i)]-1 << endl;
    } else{
      cout << subtree[i]-1 << endl;
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