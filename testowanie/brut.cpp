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

int n,m;
int u,v;
int cnt;
const int maxn = 5e4+1;
vector<int> adj[maxn];
bool vis[maxn];

void dfs(int u){
  vis[u] = true;
  cnt++;
  for(auto v : adj[u]){
    if(!vis[v]) dfs(v);
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
  }

  for(int i = 1; i <= n; i++){
    cnt = 0;
    for(int j = 1; j <= n; j++) vis[j] = false;
    dfs(i);
    cout << cnt-1 << endl;
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