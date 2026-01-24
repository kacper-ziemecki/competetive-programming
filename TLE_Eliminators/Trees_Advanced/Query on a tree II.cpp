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

ll n;
ll u,v,w,k;
ll timer;
string query;
const ll N = 10000+1;
const ll L = ceil(log2(N))+1;
vector<pair<ll,ll>> adj[N];
ll up[N][L], cost[N][L], timein[N], timeout[N], depth[N];

void precompute(ll u, ll p){
  timein[u] = timer++;
  depth[u] = depth[p]+1;
  up[u][0] = p;
  for(ll i = 1; i < L; i++){
    up[u][i] = up[up[u][i-1]][i-1];
    cost[u][i] = cost[u][i-1]+cost[up[u][i-1]][i-1];
  }
  for(auto node : adj[u]){
    if(node.first != p){
      cost[node.first][0] = node.second;
      precompute(node.first, u);
    }
  }
  timeout[u] = timer++;
}

ll calcDist(ll a, ll b){
  if(depth[a] < depth[b]) swap(a,b);
  ll diff = depth[a]-depth[b];
  ll res = 0;
  for(ll i = L-1; i >= 0; i--){
    if(diff & (1<<i)){
      res += cost[a][i];
      a = up[a][i];
    }
  }
  for(ll i = L-1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      res += cost[a][i] + cost[b][i];
      a = up[a][i];
      b = up[b][i];
    }
  }
  if(a != b) res += cost[a][0] + cost[b][0];
  return res;
}

ll lca(ll a, ll b){
  if(depth[a] < depth[b]) swap(a,b);
  ll diff = depth[a]-depth[b];
  for(ll i = L-1; i >= 0; i--) if(diff & (1<<i)) a = up[a][i];
  for(ll i = L-1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  }
  if(a != b) a = up[a][0];
  return a;
}

ll kthNode(ll a, ll b, ll k){
  ll lc = lca(a,b);
  ll diff = depth[a]-depth[lc];
  // dbg(a,b,lc,diff,k);
  if(diff >= k){
    for(ll i = L-1; i >= 0; i--) if(k & (1<<i)) a = up[a][i];
    return a;
  } else{
    diff = (depth[a]-depth[lc])+(depth[b]-depth[lc])-k;
    for(ll i = L-1; i >= 0; i--) if(diff & (1<<i)) b = up[b][i];
    return b;
  }
}

void solve(){
  cin >> n;
  for(ll i = 0; i < N; i++){
    adj[i].clear();
    depth[i] = 0;
    timein[i] = 0;
    timeout[i] = 0;
    for(ll j = 0; j < L; j++){
      up[i][j] = 0;
      cost[i][j] = 0;
    }
  }
  timer = 0;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }
  precompute(1,1);
  while(cin >> query, query != "DONE"){
    if(query == "DIST"){
      cin >> u >> v;
      cout << calcDist(u,v) << endl;
    } else{
      cin >> u >> v >> k;
      cout << kthNode(u,v,k-1) << endl;
    }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}