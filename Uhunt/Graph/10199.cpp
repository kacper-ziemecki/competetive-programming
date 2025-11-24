#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

unordered_map<string, ll> mp;
vector<vector<ll>> adj;
vector<ll> dfs_num, dfs_low, dfs_parent, articulation_vertex;
ll root, rootChildren, dfsCnt;

void dfs(ll u){
  dfs_num[u] = dfs_low[u] = ++dfsCnt;
  for(ll v : adj[u]){
    if(!dfs_num[v]){
      dfs_parent[v] = u;
      if(u == root) rootChildren++;
      dfs(v);
      if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u]=1;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void solve(ll n){
  mp.clear();
  adj.assign(n, vector<ll>());
  dfs_num.assign(n, 0);
  dfs_low.assign(n, 0);
  dfs_parent.assign(n, 0);
  articulation_vertex.assign(n, 0);
  vector<string> list(n);
  string s1,s2;
  for(ll i = 0; i < n; i++){
    cin >> s1;
    list[i] = s1;
    mp[s1]=i;
  }
  ll m;
  cin >> m;
  for(ll i = 0; i < m; i++){
    cin >> s1 >> s2;
    adj[mp[s1]].push_back(mp[s2]);
    adj[mp[s2]].push_back(mp[s1]);
  }
  for(ll i = 0; i < n; i++){
    if(!dfs_num[i]){
      dfsCnt=0;
      root=i;
      rootChildren=0;
      dfs(i);
      articulation_vertex[i]=(rootChildren>1);
    }
  }
  vector<string> res;
  for(ll i = 0; i < n; i++) if(articulation_vertex[i]) res.push_back(list[i]);
  sort(res.begin(), res.end());
  cout << res.size() << " camera(s) found\n";
  for(auto el : res) cout << el << endl;
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

  ll n;
  ll t=0;
  while(cin >> n, n != 0){
    if(t!=0) cout << endl;
    cout << "City map #" << ++t << ": ";
    solve(n);
  }
}