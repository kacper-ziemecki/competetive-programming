#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m,k;
const int N = 1e3+1;
set<int> roots,vis;
int u,v;

struct DSU{
  vector<int> p,sajz, edges;
  DSU(int n){
    sajz.assign(n+1,1);
    edges.assign(n+1,0);
    p.resize(n+1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  int findSet(int a){
    return (a == p[a] ? a : p[a] = findSet(p[a]));
  }
  void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    edges[a]++;
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
    edges[a] += edges[b];
  }
};

void solve(){
  cin >> n >> m >> k;
  DSU dsu(n+1);
  for(int i = 0; i < k; i++){
    cin >> u;
    roots.emplace(u);
  }
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    dsu.unionSet(u,v);
  }
  int res = 0;
  int biggest=0;
  for(auto root : roots){
    int s = dsu.sajz[dsu.findSet(root)];
    int e = dsu.edges[dsu.findSet(root)];
    res += (s*(s-1)/2) - e;
    biggest = max(biggest, s);
    vis.emplace(dsu.findSet(root));
  }
  for(int u = 1; u <= n; u++){
    if(vis.count(dsu.findSet(u))) continue;
    vis.emplace(dsu.findSet(u));
    for(int i = 1; i <= dsu.sajz[dsu.findSet(u)]; i++){
      res += biggest++;
    }
    res -= dsu.edges[dsu.findSet(u)];
  }
  cout << res << endl;
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

  solve();
}