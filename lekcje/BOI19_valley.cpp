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

vector<pair<ll,ll>> adj[100001];
ll dist_from_e[100001];
ll dist_from_shops[100001];
ll combined_distance[100001];
ll preorder[100001], postorder[100001];
ll subtree_size[100001];
ll path_index[100001];
ll parent[100001];
ll timer=0, height=0;
set<ll> shops;

struct SegTree{
  struct Node{
    ll minimum_weight;
    ll minimum_node;
    Node(): minimum_weight{100}, minimum_node{1}{} // zmieeeeeeeeeeeeeeeeeeeeeniccccccccccc na LLONG_MAX
  };
  vector<Node> nodes;
  ll length;

  SegTree(ll n): length{1}{
    while(length <= n) length <<= 1;
    nodes.resize(length*2);
  }
  // [l...r)
  void set(ll v, ll val, ll l, ll r, ll x){
    if(r-l==1){
      nodes[x].minimum_weight = val;
      nodes[x].minimum_node = l;
      return;
    }
    ll mid = (l+r)/2;
    if(v < mid) set(v,val,l,mid,x*2);
    else set(v,val,mid,r,x*2+1);
    nodes[x].minimum_weight = min(nodes[x*2].minimum_weight, nodes[x*2+1].minimum_weight);
    if(nodes[x*2].minimum_weight < nodes[x*2+1].minimum_weight) nodes[x].minimum_node = nodes[x*2].minimum_node;
    else nodes[x].minimum_node = nodes[x*2+1].minimum_node;
  }

  void set(ll v, ll val){
    set(v, val, 0, length, 1);
  }

  ll get(ll l, ll r, ll lx, ll rx, ll x){
    if(r <= lx || l >= rx) return LLONG_MAX;
    if(l <= lx && r >= rx){
      // dbg(l,r,lx,rx,x);
      return nodes[x].minimum_weight;
    }
    ll mid=(lx+rx)/2;
    return min(get(l,r,lx,mid,x*2), get(l,r,mid,rx,x*2+1));
  }

  ll get(ll l, ll r){
    return get(l,r,0,length,1);
  }
};

ll dfsPrecompute(ll u, ll p){
  subtree_size[u] = 1;
  parent[u] = p;
  height = max(height, dist_from_e[u]);
  if(shops.count(u)) dist_from_shops[u] = 0;
  for(auto v : adj[u]){
    if(v.first == p) continue;
    // dbg(v.first, v.second);
    dist_from_e[v.first] = dist_from_e[u] + v.second;
    ll dist_v = dfsPrecompute(v.first, u);
    if(dist_v != LLONG_MAX) dist_from_shops[u] = min(dist_from_shops[u], dist_v+v.second);
    subtree_size[u] += subtree_size[v.first];
  }
  return dist_from_shops[u];
}

void dfsHld(ll u, ll p){
  ll max_subtree = 0;
  ll max_node = 0;
  preorder[u] = ++timer;
  for(auto v : adj[u]){
    if(v.first == p) continue;
    if(max_subtree < subtree_size[v.first]){
      max_subtree = subtree_size[v.first];
      max_node = v.first;
    } 
  }
  if(max_subtree != 0){
    path_index[max_node] = path_index[u];
    dfsHld(max_node, u);
    for(auto v : adj[u]){
      if(v.first == p || v.first == max_node) continue;
      path_index[v.first] = v.first;
      dfsHld(v.first, u);
    }
  }
  postorder[u] = timer;
}

bool is_ancestor(ll up, ll low){
  return (preorder[up] <= preorder[low] && postorder[up] >= postorder[low]);
}

void solve()
{
  ll n,s,q,e,a,b;
  cin >> n >> s >> q >> e;
  vector<vector<ll>> lista(n, vector<ll>(3, 0));
  memset(dist_from_e, 0, sizeof(dist_from_e));
  for(ll i = 0; i <= n; i++) dist_from_shops[i] = LLONG_MAX;
  memset(subtree_size, 0, sizeof(subtree_size));
  memset(path_index, 0, sizeof(subtree_size));
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < 3; j++) cin >> lista[i][j];
  }
  for(auto el : lista){
    adj[el[0]].pb({el[1], el[2]});
    adj[el[1]].pb({el[0], el[2]});
  }
  for(ll i = 0; i < s; i++){
    cin >> a;
    shops.emplace(a);
  }
  // for(ll i = 1; i <= n; i++){
  //   cout << dist_from_shops[i] << " ";
  // }
  // cout << endl;
  dfsPrecompute(e, e);
  for(ll u = 1; u<=n; u++){
    if(dist_from_shops[u] == LLONG_MAX) combined_distance[u] = LLONG_MAX;
    else combined_distance[u] = dist_from_shops[u]+(height-dist_from_e[u]);
  }
  SegTree seg_tree(n);
  path_index[e] = e;
  dfsHld(e, e);
  for(ll u = 1; u <= n; u++) seg_tree.set(preorder[u], combined_distance[u]);
  // for(ll i = 1; i <= n; i++) cout << preorder[i] << " ";
  // cout << endl;
  // for(ll i = 1; i <= n; i++){
  //   cout << dist_from_shops[i] << " ";
  // }
  // cout << endl;
  // for(ll i = 1; i <= n; i++){
  //   cout << dist_from_e[i] << " ";
  // }
  // cout << endl;
  // for(ll i = 1; i <= n; i++){
  //   cout << combined_distance[i] << " ";
  // }
  // cout << endl;
  // for(auto node : seg_tree.nodes){
  //   cout << node.minimum_weight << " ";
  // }
  // cout << endl;
  for(ll i = 0; i < q; i++){
    cin >> a >> b;
    if(is_ancestor(lista[a-1][0], b) && is_ancestor(lista[a-1][1], b)){
      if(dist_from_e[lista[a-1][0]] > dist_from_e[lista[a-1][1]]){
        a = lista[a-1][0];
      } else{
        a = lista[a-1][1];
      }
      // dbg(a, b);
      ll begining = b, res = LLONG_MAX;
      while(path_index[a] != path_index[b]){
        if(dist_from_e[path_index[a]] > dist_from_e[path_index[b]]) swap(a,b);
        // dbg(path_index[b], preorder[b], preorder[path_index[b]], res);
        res = min(res, seg_tree.get(preorder[path_index[b]], preorder[b]+1));
        b = parent[path_index[b]];
        // dbg(a, b, res);
      }
      // dbg(a,b,res);
      // dbg(seg_tree.get(min(preorder[a], preorder[b]+1), max(preorder[a], preorder[b]+1)));
      res = min(res, seg_tree.get(min(preorder[a], preorder[b]+1), max(preorder[a], preorder[b]+1)));
      // dbg(res, begining);
      if(res == LLONG_MAX){
        cout << "oo\n";
      } else{
        cout << res - (height-dist_from_e[begining]) << endl;
      }
    } else{
      cout << "escaped\n";
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