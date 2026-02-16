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

int n,m,k,s;
int u,v;
const int N = 1e5+1;
const int K = 101;
const int INF = 1e7;
int dist[N][K];
int color[N];
vector<int> adj[N];
vector<int> grups[K];

void solve(){
  cin >> n >> m >> k >> s;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < K; j++) dist[i][j] = INF;
  }
  for(int i = 0; i < n; i++) cin >> color[i+1];
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(int i = 1; i <= n; i++) grups[color[i]].pb(i);
  for(int i = 1; i <= k; i++){
    queue<int> q;
    for(auto el : grups[i]){
      q.push(el);
      dist[el][i] = 0;
    }
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(auto v : adj[u]){
        if(dist[v][i] != INF) continue;
        dist[v][i] = dist[u][i]+1;
        q.push(v);
      }
    }
  }
  for(int u = 1; u <= n; u++){
    sort(dist[u], dist[u]+K);
    int res = 0;
    for(int i = 0; i < s; i++) res += dist[u][i];
    cout << res << ' ';
  }
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