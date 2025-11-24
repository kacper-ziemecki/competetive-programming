#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int u,v;
const int maxN = 1e5+1;
vector<int> adj[maxN], counts;
bitset<maxN> current,previous;
bool vis[maxN];

int dfs(int u){
  vis[u] = true;
  int count = 1;
  for(auto v : adj[u]){
    if(!vis[v]) count += dfs(v);
  }
  return count;
}


void solve()
{
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]) counts.pb(dfs(i));
  }
  current[0] = 1;
  current[counts[0]] = 1;
  for(int i = 1; i < counts.size(); i++){
    swap(current,previous);
    current = previous | (previous << counts[i]);
  }
  string s = current.to_string();
  int index = s.find('1');
  string res = s.substr(index);
  reverse(res.begin(),res.end());
  res = res.substr(1);
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}