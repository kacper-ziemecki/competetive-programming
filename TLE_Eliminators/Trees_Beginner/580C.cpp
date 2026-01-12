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
const int maxn = 1e5+1;
bool cat[maxn];
int cnt[maxn];
int res = 0;
vector<int> tree[maxn];

void dfs(int u, int p){
  if(cat[u]){
    cnt[u] = cnt[p] + cat[u];
  } 
  // dbg(cnt[u], u,m );
  if(cnt[u] > m) return;
  if(tree[u].size() == 1 && u != 1){
    res++;
  }
  for(auto v : tree[u]){
    if(v != p) dfs(v,u);
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> cat[i];
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  dfs(1, 1);
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