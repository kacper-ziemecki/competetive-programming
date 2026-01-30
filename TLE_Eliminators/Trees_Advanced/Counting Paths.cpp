#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int u,v;
int timer;
const int N = 2e5+1, M = 2e5+1;
const int L = ceil(log2(N))+1;
vector<int> adj[N];
int lca_cnt[N], subtree_lca[N], cnt[N];
int timein[N],timeout[N],up[N][L];
int ans[N];

void precompute(int u, int p){
  timein[u] = timer++;
  up[u][0] = p;
  for(int i = 1; i < L; i++) up[u][i] = up[up[u][i-1]][i-1];
  for(auto v : adj[u]) if(v != p) precompute(v,u);
  timeout[u] = timer++;
}

bool isAncestor(int a, int b){
  if(timein[a] <= timein[b] && timeout[a] >= timeout[b]) return true;
  return false;
}

int lca(int a, int b){
  if(isAncestor(a,b)) return a;
  if(isAncestor(b,a)) return b;
  for(int i = L-1; i >= 0; i--){
    if(!isAncestor(up[a][i], b)) a = up[a][i]; 
  }
  return up[a][0];
}

void second_precompute(int u, int p){
  subtree_lca[u] = lca_cnt[u];
  for(auto v : adj[u]){
    if(v != p){
      second_precompute(v,u);
      subtree_lca[u] += subtree_lca[v];
      cnt[u] += cnt[v];
    }
  }
}

void calc_every_ans(int u, int p){
  ans[u] = cnt[u] - lca_cnt[u] - 2*(subtree_lca[u]-lca_cnt[u]);
  for(auto v : adj[u]) if(v != p) calc_every_ans(v,u);
}
void solve(){
  cin >> n >> m;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  precompute(1,1);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    cnt[u]++;
    cnt[v]++;
    lca_cnt[lca(u,v)]++;
  }
  second_precompute(1,1);
  calc_every_ans(1,1);
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
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