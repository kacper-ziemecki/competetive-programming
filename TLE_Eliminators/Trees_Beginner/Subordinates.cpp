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

int n,p;
const int maxn = 2e5+1;
vector<int> adj[maxn];
int subtree[maxn];

int dfs(int u){
  subtree[u] = 1;
  for(auto v : adj[u]){
    subtree[u] += dfs(v);
  }
  return subtree[u];
}

void solve(){
  cin >> n;
  for(int i = 2; i <= n; i++){
    cin >> p;
    adj[p].pb(i);
  }
  dfs(1);
  for(int i = 1; i <= n; i++){
    cout << subtree[i]-1 << ' ';
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