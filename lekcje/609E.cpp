#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


const ll maxN = 2e5+1;
const ll l = ceil(log2(maxN));
vector<pair<ll,ll>> adj[maxN], adj_mst[maxN];
vector<vector<ll>> edges, pierwotne_edges;
ll p[maxN], _size[maxN], up[maxN][l+1], mx[maxN][l+1], preorder[maxN], postorder[maxN];
ll timer=0;

ll getSet(ll a){
  return (p[a] == a ? a : p[a] = getSet(p[a]));
}

void unionSet(ll a, ll b){
  a = getSet(a);
  b = getSet(b);
  if(a == b) return;
  if(_size[a] < _size[b]) swap(a,b);
  p[b] = a;
  _size[a] += _size[b];
}

void dfs(ll u, ll p, ll koszt=0){
  preorder[u] = ++timer;
  up[u][0] = p;
  mx[u][0] = koszt;
  for(ll i = 1; i <= l; i++){
    up[u][i] = up[up[u][i-1]][i-1];
    mx[u][i] = max(mx[u][i-1], mx[up[u][i-1]][i-1]);
  }
  for(auto [v, w] : adj_mst[u]){
    if(v == p) continue;
    dfs(v,u,w);
  }
  postorder[u] = timer;
}

bool is_ancestor(ll gora, ll dol){
  return (preorder[gora] <= preorder[dol] && postorder[gora] >= postorder[dol]);
}

ll maks(ll a, ll b){
  if(is_ancestor(a,b)) return 0;
  ll res = 0;
  for(ll i = l; i >= 0; i--){
    if(!is_ancestor(up[a][i], b)){
      res = max(res, mx[a][i]);
      a = up[a][i];
    }
  }
  res = max(res, mx[a][0]);
  return res;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  ll u,v,w;
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    edges.pb({w,u,v});
    pierwotne_edges.pb({w,u,v});
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }
  sort(edges.begin(), edges.end());
  for(ll i = 1; i <= n; i++){
    p[i] = i;
    _size[i] = 1;
  }
  ll mst_cost=0;
  for(auto edge : edges){
    if(getSet(edge[1]) != getSet(edge[2])){
      unionSet(edge[1], edge[2]);
      mst_cost += edge[0];
      adj_mst[edge[1]].pb({edge[2], edge[0]});
      adj_mst[edge[2]].pb({edge[1], edge[0]});
    }
  }

  dfs(1,1);
  for(auto edge : pierwotne_edges){
    cout << mst_cost - max(maks(edge[1], edge[2]), maks(edge[2],edge[1])) + edge[0] << endl;
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}