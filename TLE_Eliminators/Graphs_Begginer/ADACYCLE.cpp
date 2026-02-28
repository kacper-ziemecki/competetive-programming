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

int n;
const int N = 2e3+1;
const int INF = 1e7;
vector<int> adj[N];
bool matrix[N][N];
int dist[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> matrix[i][j];
      if(matrix[i][j]){
        adj[i].pb(j);
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) dist[j] = INF;
    dist[i] = 0;
    bool flag=false;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int u = q.front(); q.pop();
      // dbg(i,u);
      for(auto v : adj[u]){
        // dbg(i,v);
        if(v == i){
          flag = true;
          cout << dist[u]+1 << endl;
          break;
        }
        if(dist[v] == INF){
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
      if(flag) break;
    }
    if(!flag){
      cout << "NO WAY\n";
    }
  }
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