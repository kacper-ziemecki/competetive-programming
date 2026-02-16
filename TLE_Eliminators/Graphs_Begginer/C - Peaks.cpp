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

int n,m;
int u,v;
const int N = 1e5+1;
vector<int> adj[N];
int h[N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> h[i+1];
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int res=0;
  for(int u = 1; u <= n; u++){
    bool flag = true;
    for(auto v : adj[u]){
      if(h[v] >= h[u]){
        flag = false;
        break;
      }
    }
    if(flag){
      res++;
    }
  }
  cout << res << endl;
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