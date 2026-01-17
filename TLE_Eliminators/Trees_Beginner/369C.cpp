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

int n;
int u,v,k;
const int maxn = 1e5+1;
vector<int> tree[maxn];
bool bad[maxn];
vector<int> res;

bool dfs(int u, int p){
  bool flag = false;
  for(auto v : tree[u]){
    if(v != p) flag = flag | dfs(v,u);
  }
  if(!flag && bad[u]){
    res.pb(u); 
    flag = true;
  }
  return flag;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v >> k;
    tree[u].pb(v);
    tree[v].pb(u);
    if(k == 2) bad[v] = bad[u] = true;
  }
  dfs(1,1);
  cout << res.size() << endl;
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