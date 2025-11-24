#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ll> dfs_num,dfs_low,dfs_parent;
vector<vector<ll>> adj;
vector<pair<ll,ll>> res;
ll dfsCnt;

ll to_number(string s){
  s = s.substr(1, s.size()-2);
  return stoll(s);
}

void dfs(ll u){
  dfs_num[u] = dfs_low[u] = ++dfsCnt;
  for(ll v : adj[u]){
    if(!dfs_num[v]){
      dfs_parent[v] = u;
      dfs(v);
      if(dfs_low[v] > dfs_num[u]) res.push_back({u, v});
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void solve(){
  ll n;
  cin >> n;
  if(cin.eof()) return;
  dfs_num.assign(n, 0);
  dfs_low.assign(n, 0);
  dfs_parent.assign(n, 0);
  res.clear();
  adj.assign(n, vector<ll>());
  for(ll i = 0; i < n; i++){
    ll u,v;
    string s;
    cin >> u >> s;
    ll cnt = to_number(s);
    for(ll j = 0; j < cnt; j++){
      cin >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  for(ll i = 0; i < n; i++){
    if(!dfs_num[i]){
      dfsCnt=0;
      dfs(i);
    }
  }
  cout << res.size() << " critical links\n";
  for(auto &el : res){
    if(el.first > el.second) swap(el.first, el.second);
  }
  sort(res.begin(), res.end());
  for(auto el : res) cout << el.first << " - " << el.second << endl;
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

  ll t=0;
  while(!cin.eof()){
    if(t++ != 0) cout << endl;
    solve();
  }

}