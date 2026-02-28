#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


int n;
int u,v;
const int N = 5e5+1;
vector<int> adj[N];
int subtree_size[N];
int centroid,ile_controidow;

void znajdz_centroid(int u, int p){
  subtree_size[u] = 1;
  bool moze_byc_centroidem = true;
  for(auto v : adj[u]){
    if(v == p) continue;
    znajdz_centroid(v,u);
    subtree_size[u] += subtree_size[v];
    if(subtree_size[v] > n/2) moze_byc_centroidem = false;
  }
  if(n-subtree_size[u] > n/2) moze_byc_centroidem = false;
  if(moze_byc_centroidem){
    centroid = u;
    ile_controidow++;
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  znajdz_centroid(1,1);
  dbg(centroid, ile_controidow);
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