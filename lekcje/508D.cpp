#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void dfs(string u, unordered_map<string, vector<string>>& adj, unordered_map<string, vector<bool>>& vis, vector<string> &res, ll &cnt, unordered_map<string, ll>& begining){

  for(; begining[u] < adj[u].size(); begining[u]++){
    if(!vis[u][begining[u]]){
      vis[u][begining[u]] = true;
      cnt--;
      dfs(adj[u][begining[u]],adj,vis,res,cnt,begining);
    }
  }
  res.pb(u);
}

void solve()
{
  ll n,cnt=0;
  cin >> n;
  vector<string> list(n);
  set<string> nodes;
  unordered_map<string, vector<string>> adj;
  unordered_map<string, vector<bool>> vis;
  unordered_map<string, ll> in_deg,out_deg,begining;
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    adj[list[i].substr(0,2)].pb(list[i].substr(1,2));
    cnt++;
    nodes.emplace(list[i].substr(0,2)); nodes.emplace(list[i].substr(1,2));
  }
  for(auto el : adj){
    vis[el.first].assign((ll)el.second.size(), false);
    out_deg[el.first] = el.second.size();
    for(auto v : el.second) in_deg[v]++;
  }
  bool is_cycle=true;
  ll source = 0, dest = 0;
  for(auto node : nodes){
    // dbg(list[i].substr(1,2), in_deg[list[i].substr(1,2)], out_deg[list[i].substr(1,2)], in_deg[list[i].substr(1,2)]-out_deg[list[i].substr(1,2)]);
    if(out_deg[node]==in_deg[node]);
    else if(out_deg[node]-in_deg[node] == 1) source++;
    else if(in_deg[node]-out_deg[node] == 1) dest++;
    else is_cycle = false;
  }
  // dbg(source, dest);
  // for(auto el : adj){
  //   cout << el.first << " -> ";
  //   for(auto sub : el.second) cout << sub << " , ";
  //   cout << endl;
  // }
  if(!is_cycle || ((source != 1 || dest != 1) && adj.size() != 1 && !(source == 0 && dest == 0))){ cout << "NO\n"; return; }

  // dbg(source, dest, is_cycle);
  string s;
  vector<string> res;
  for(auto el : adj){ 
    if(out_deg[el.first]-in_deg[el.first] == 1) s=el.first;
    if(adj.size()==1 || (source == 0 && dest == 0)) s = el.first;
  }
  // dbg(s);
  dfs(s, adj, vis, res, cnt, begining);
  if(cnt != 0){ cout << "NO\n"; return; }
  if(adj.size()==1){cout << "YES\n" << string(n+2,list[0][0]) << endl; return; }
  reverse(res.begin(),res.end());
  cout << "YES\n";
  for(ll i = 0; i < res.size(); i++){
    if(i) cout << res[i][1];
    else cout << res[i];
  }
  cout << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  
  solve();
}