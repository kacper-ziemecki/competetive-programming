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
vector<ll> adj[maxN], adj_t[maxN], trees[maxN];
vector<ll> topo;
set<ll> roots;
bool is_root[maxN];
ll vis[maxN], cast[maxN], reverse_cast[maxN], scc_size[maxN], preorder[maxN], postorder[maxN], depth[maxN], before_root[maxN], order[maxN];
ll cnt=1, timer=1;

struct Dsu{
  vector<ll> p,_size;
  Dsu(ll n){
    p.resize(n+1); _size.assign(n+1, 1);
    for(ll i = 0; i <= n; i++) p[i] = i;
  }
  ll getSet(ll a){ return (p[a] == a ? a : p[a] = getSet(p[a])); }
  void unionSet(ll a, ll b){
    a = getSet(a);
    b = getSet(b);
    if(_size[a] < _size[b]) swap(a,b);
    p[b] = a;
    _size[a] += _size[b];
  }
  bool in_same_set(ll a, ll b){ return (getSet(a) == getSet(b)); }
};

void topo_sort(ll u){
  vis[u] = 1;
  if(!vis[adj[u][0]]) topo_sort(adj[u][0]);
  topo.pb(u);
}

void scc(ll u, ll cnt){
  // dbg(u, cnt);
  vis[u] = 1;
  cast[u] = cnt;
  order[u] = timer++;
  reverse_cast[cnt] = u; // jezeli scc ma wiecej niz jeden element to tylko zapisujemy jakis jeden randomowy
  scc_size[cnt]++;
  for(ll v : adj_t[u]){
    if(vis[v] == 1){
      roots.emplace(cnt);
      is_root[cnt] = true;
    }
    if(!vis[v]) scc(v,cnt);
  }
  vis[u] = 2;
}

void preprocess_tree(ll u, ll p, ll bf_root=-1){
  // dbg(u,timer);
  before_root[u] = bf_root;
  preorder[u] = ++timer;
  for(ll v : trees[u]){
    if(v == p) continue;
    depth[v] = depth[u]+1;
    if(bf_root == -1) preprocess_tree(v,u,v);
    else preprocess_tree(v,u,bf_root);
  }
  postorder[u] = timer;
}

bool is_ancestor(ll up, ll down){return (preorder[up] <= preorder[down] && postorder[up] >= postorder[down]); }

void solve()
{
  ll n,q;
  cin >> n >> q;
  ll a,b;
  for(ll i = 1; i <= n; i++){
    cin >> a;
    adj[i].pb(a);
    adj_t[a].pb(i);
  }
  memset(vis, 0, n+1);  
  for(ll u = 1; u <= n; u++){
    if(!vis[u]) topo_sort(u);
  }
  reverse(topo.begin(), topo.end());
  // for(auto el : topo) cout << el << " ";
  // cout << endl;
  // cout << "adj\n";
  // for(ll u = 1; u <= n; u++){
  //   cout << u << " -> ";
  //   for(ll v : adj[u]) cout << v << ", ";
  //   cout << endl;
  // }
  // cout << "adj_t\n";
  // for(ll u = 1; u <= n; u++){
  //   cout << u << " -> ";
  //   for(ll v : adj_t[u]) cout << v << ", ";
  //   cout << endl;
  // }
  for(ll u = 1; u <= n; u++) vis[u] = 0; // 0 - nie odwiedzony, 1 - wlasnie odwiedzony, 2 - dawno odwiedzony
  memset(scc_size, 0, n+1);
  memset(is_root, false, n+1);
  for(auto u : topo){
    timer=1;
    // dbg(u);
    // for(ll v = 1; v <= n; v++) dbg(v, vis[v]);
    if(!vis[u]){ scc(u,cnt); cnt++; }
  }
  // cout << "vis:\n";
  // for(ll u = 1; u <= n; u++) cout << vis[u] << " ";
  // cout << endl;
  // cout << "cast\n";
  // for(ll u = 1; u <= n; u++) cout << u << " -> " << cast[u] << endl;
  // cout << "reverse_cast\n";
  // for(ll u = 1; u <= n; u++) cout << u << " -> " << reverse_cast[u] << endl;
  Dsu dsu(n);
  for(ll u = 1; u <= n; u++){
    if(!dsu.in_same_set(cast[u], cast[adj[u][0]])){
      trees[cast[u]].pb(cast[adj[u][0]]);
      trees[cast[adj[u][0]]].pb(cast[u]);
      dsu.unionSet(cast[u], cast[adj[u][0]]);
    }
  }
  // cout << "trees:\n";
  // for(ll u = 1; u <= n; u++){
  //   cout << u << " -> ";
  //   for(ll v : trees[u]) cout << v << ", ";
  //   cout << endl;
  // }
  // cout << "roots:\n";
  // for(auto root : roots){
  //   cout << root << " ";
  // }
  // cout << endl;
  for(auto root : roots){
    depth[root] = 0;
    timer=0;
    preprocess_tree(root, root);
  }
  // cout << "preorder:\n";
  // for(ll u = 1; u <= n; u++){
  //   cout << preorder[u] << " ";
  // }
  // cout << endl;
  // cout << "postorder:\n";
  // for(ll u = 1; u <= n; u++){
  //   cout << postorder[u] << " ";
  // }
  // cout << endl;
  // cout << "order\n";
  // for(ll u = 1; u <= n; u++) cout << order[u] << " ";
  // cout << endl;

  for(ll i = 0; i < q; i++){
    cin >> a >> b;
    if(!dsu.in_same_set(cast[a],cast[b]) || !is_ancestor(cast[b],cast[a])){
      cout << -1 << endl;
    } else if(!is_root[cast[a]] && !is_root[cast[b]]){
      cout << depth[cast[a]]-depth[cast[b]] << endl;
    } else if(!is_root[cast[a]] && is_root[cast[b]]){
      ll dist = depth[cast[a]];
      // cout << "b in root, a is not in root\n";
      // dbg(dist);
      // dbg(cast[a], cast[b]);
      // dbg(scc_size[cast[a]], scc_size[cast[b]]);
      // dbg(before_root[cast[a]], before_root[cast[b]]);
      // dbg(reverse_cast[before_root[cast[a]]]);
      // dbg(adj[reverse_cast[before_root[cast[a]]]][0]);
      ll order_a = order[adj[reverse_cast[before_root[cast[a]]]][0]];
      ll order_b = order[b];
      // dbg(order_a, order_b);
      if(order_b <= order_a) cout << order_a-order_b+dist << endl;
      else cout << order_a + (scc_size[cast[b]]-order_b)+dist << endl;
    } else{
      // cout << "both in root\n";
      ll order_a = order[a];
      ll order_b = order[b];
      if(order_b <= order_a) cout << order_a-order_b << endl;
      else cout << order[a] + (scc_size[cast[b]]-order_b) << endl;
    }
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}