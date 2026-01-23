#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

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
  if(timein[a] <= timein[b] && timeout[a] >= timeout[b]) return true;
  return false;
}

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
  }
}

int main()
  {

  // ios_base::sync_with_stdio(0);
  // cin.tie(0); 
  // cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}