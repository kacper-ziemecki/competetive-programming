#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define endl "\n"
=======
// #define endl "\n"
>>>>>>> b093419283e028be6e7b41b3b10c14fe9d899d4c
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

<<<<<<< HEAD
int n,q;
int timer,a,b;
const int N = 2e5+1;
const int L = ceil(log2(N))+1;
vector<int> adj[N];
int timein[N],timeout[N],dp[N][L],depth[N];

void precompute(int u, int p){
  depth[u] = depth[p]+1;
  timein[u] = timer++;
  dp[u][0] = p;
  for(int i = 1; i < L; i++) dp[u][i] = dp[dp[u][i-1]][i-1];
  for(auto v : adj[u]) if(v != p) precompute(v,u);
  timeout[u] = timer++;
}

bool isAncestor(int a, int b){
=======
ll n,m,q;
ll u,v,w;
ll timer;
const int N = 3e5+1;
const int L = ceil(log2(N))+1;
vector<pair<ll,ll>> adj[N];
ll timein[N], timeout[N], up[N][L], mn[N][L], depth[N];

void precompute(ll u, ll p){
  timein[u] = timer++;
  depth[u] = depth[p]+1;
  up[u][0] = p;
  for(int i = 1; i < L; i++){
    up[u][i] = up[up[u][i-1]][i-1];
    mn[u][i] = min(mn[u][i-1], mn[up[u][i-1]][i-1]);
  }
  for(auto [v,w]: adj[u]){
    if(v != p){
      mn[v][0] = w;
      precompute(v,u);
    }
  }
  timeout[u] = timer++;
}

bool isAncestor(ll a, ll b){
>>>>>>> b093419283e028be6e7b41b3b10c14fe9d899d4c
  if(timein[a] <= timein[b] && timeout[a] >= timeout[b]) return true;
  return false;
}

<<<<<<< HEAD
int lca(int a, int b){
  if(isAncestor(a,b)) return a;
  if(isAncestor(b,a)) return b;
  for(int i = L-1; i >= 0; i--){
    if(!isAncestor(dp[a][i], b)) a = dp[a][i];
  }
  return dp[a][0];
}
void solve(){
  cin >> n >> q;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  precompute(1,1);
  for(int i = 0; i < q; i++){
    cin >> a >> b;
    int lc = lca(a,b);
    cout << depth[a]-depth[lc] + depth[b]-depth[lc] << endl;
=======
ll lca(ll a, ll b){
  if(depth[a] < depth[b]) swap(a,b);
  ll diff = depth[a]-depth[b];
  // dbg(diff,a,b);
  ll res = LLONG_MAX;
  for(int i = L-1; i >= 0; i--){
    if(diff & (1<<i)){
      res = min(res, mn[a][i]);
      a = up[a][i];
    }
  }
  for(int i = L-1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      res = min({res, mn[a][i], mn[b][i]});
      a = up[a][i];
      b = up[b][i];
    }
  }
  if(a != b) res = min({res, mn[a][0], mn[b][0]});
  return res;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < L; j++) mn[i][j] = LLONG_MAX;
  }
  precompute(1,1);
  // for(int i = 1; i <= n; i++){
  //   dbg(i);
  //   for(int j = 0; j < 2; j++){
  //     dbg(i,j,up[i][j],mn[i][j]);
  //   }
  // }
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> u >> v;
    cout << lca(u,v) << endl;
>>>>>>> b093419283e028be6e7b41b3b10c14fe9d899d4c
  }
}

int main()
  {

<<<<<<< HEAD
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
=======
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); 
  // cout.tie(0);
>>>>>>> b093419283e028be6e7b41b3b10c14fe9d899d4c

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}