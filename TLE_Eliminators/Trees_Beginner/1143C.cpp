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

int n,p,root;
const int maxn = 1e5+1;
vector<int> adj[maxn];
vector<int> res;
bool flaga[maxn];

void dfs(int u){
  bool f = !flaga[u];
  for(auto v : adj[u]) f = f | !flaga[v];
  if(!f) res.pb(u);
  for(auto v : adj[u]) dfs(v);
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> p >> flaga[i];
    if(p == -1) root = i;
    else adj[p].pb(i);
  }
  dfs(root);
  sort(res.begin(), res.end());
  if(res.empty()) cout << -1;
  for(auto el : res) cout << el << ' ';
  cout << endl;
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