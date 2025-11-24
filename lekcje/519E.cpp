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

const ll maxN = 1e5+1;
const ll l = ceil(log2(maxN));
vector<ll> adj[maxN];
ll dp[maxN][l+1], preorder[maxN], postorder[maxN], dist[maxN], subtree_size[maxN];
ll timer=0;

ll dfs(ll u, ll p){
  ll cur_subtree_size=1;
  preorder[u] = ++timer;
  dp[u][0] = p;
  for(ll i = 1; i <= l; i++) dp[u][i] = dp[dp[u][i-1]][i-1];
  for(ll v : adj[u]){
    if(v == p) continue;
    dist[v] = dist[u]+1;
    cur_subtree_size += dfs(v,u);
  }
  postorder[u] = timer;
  return subtree_size[u] = cur_subtree_size;
}

bool is_ancestor(ll up, ll down){ return (preorder[up] <= preorder[down] && postorder[up] >= postorder[down]); }

ll lca(ll u, ll v){
  if(is_ancestor(u,v)) return u;
  if(is_ancestor(v,u)) return v;
  for(ll i = l; i >= 0; i--){
    if(!is_ancestor(dp[u][i], v)) u = dp[u][i];
  }
  return dp[u][0];
}

void solve()
{
  ll n,u,v;
  cin >> n;
  for(ll i = 1; i < n; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dist[1] = 0;
  dfs(1,1);
  ll q;
  cin >> q;
  for(ll i = 0; i < q; i++){
    cin >> u >> v;
    ll lca_wierzcholek = lca(u,v);
    ll lca_distance = dist[lca_wierzcholek];
    ll distance = dist[u]+dist[v]-2*lca_distance;
    ll wynik;
    // dbg(distance);
    if(distance&1){ cout << 0 << endl; continue; }
    if(dist[u] == dist[v]){
      //przypadek gdzie ten srodkowy to lca(u,v)
      ll przed_lca_od_u=u, przed_lca_od_v=v;
      for(ll i = l; i >= 0; i--){
        if(dist[dp[przed_lca_od_u][i]] > lca_distance) przed_lca_od_u = dp[przed_lca_od_u][i];
      }
      for(ll i = l; i >= 0; i--){
        if(dist[dp[przed_lca_od_v][i]] > lca_distance) przed_lca_od_v = dp[przed_lca_od_v][i];
      }
      if(u==v) wynik = n;
      else wynik = subtree_size[lca_wierzcholek] - subtree_size[przed_lca_od_u] - subtree_size[przed_lca_od_v] + n-subtree_size[lca_wierzcholek];
    } else{
      //srodkowy nie jest naszym lca(u,v)
      ll distance_srodka = max(dist[u], dist[v])-(distance/2);
      ll przed_srodkiem,srodek=(dist[u] < dist[v] ? v : u);
      for(ll i = l; i >= 0; i--){
        if(dist[dp[srodek][i]] > distance_srodka) srodek = dp[srodek][i];
      }
      przed_srodkiem = srodek;
      srodek = dp[srodek][0];
      // dbg(srodek, przed_srodkiem, subtree_size[srodek], subtree_size[przed_srodkiem]);
      wynik = subtree_size[srodek] - subtree_size[przed_srodkiem];
    }
    cout << wynik << endl;
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}