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

void dfs(ll u, unordered_map<ll, vector<ll>>& adj, unordered_map<ll, vector<bool>>& vis, vector<ll>& order, ll& counter){
  for(ll i = 0; i < adj[u].size(); i++){
    if(!vis[u][i]){
      vis[u][i] = true;
      counter--;
      dfs(adj[u][i],adj,vis,order,counter);
    }
  }
  order.pb(u);
}

void solve()
{
  ll n,k,cnt=0,source = 0, dest = 0,counter;
  cin >> n >> k;
  counter = n;
  vector<string> list(n);
  unordered_map<string, ll> s_to_l;
  unordered_map<ll, string> l_to_s;
  unordered_map<ll, vector<ll>> adj;
  unordered_map<ll, vector<bool>> vis;
  unordered_map<ll, ll> in_deg,out_deg;
  for(auto &el : list) cin >> el;
  if(k == 1){
    for(auto el : list) cout << el;
    cout << endl;
    return;
  }
  for(auto &el : list){
    if(!s_to_l.count(el.substr(0,k-1))) s_to_l[el.substr(0,k-1)] = cnt++;
    if(!s_to_l.count(el.substr(1,k-1))) s_to_l[el.substr(1,k-1)] = cnt++;
  }
  for(auto el : s_to_l) l_to_s[el.second] = el.first;
  // for(auto el : s_to_l) cout << el.first << " -> " << el.second << endl;
  // cout << endl;
  for(auto el : list) adj[s_to_l[el.substr(0,k-1)]].pb(s_to_l[el.substr(1,k-1)]);
  for(ll i = 0; i < adj.size(); i++) vis[i].assign((ll)adj[i].size(), false);
  // for(auto el : adj){
  //   cout << el.first << " -> ";
  //   for(auto v : el.second) cout << v << " ";
  //   cout << endl;
  // }
  // cout << endl;
  for(auto el : adj){
    for(auto v : el.second){
      in_deg[v]++; 
      out_deg[el.first]++;
    }
  }
  bool no_cycle = false;
  for(auto el : s_to_l){
    // dbg(el.second, in_deg[el.second], out_deg[el.second]);
    if(out_deg[el.second] == in_deg[el.second]);
    else if(out_deg[el.second]-in_deg[el.second] == 1) source++;
    else if(in_deg[el.second]-out_deg[el.second] == 1) dest++;
    else no_cycle = true;
  }
  // dbg(no_cycle, source, dest, adj.size());
  if(no_cycle || ((!(source == 1 && dest == 1) && !(source == 0 && dest == 0) && adj.size() != 1))){cout << -1 << endl; return; }

  ll s;
  for(auto el : s_to_l){
    if(out_deg[el.second]-in_deg[el.second] == 1) s = el.second;
    if(adj.size() == 1 || (source == 0 && dest == 0)) s = el.second;
  }
  vector<ll> order;
  dfs(s,adj,vis,order,counter);
  // dbg(counter,s);
  if(counter){ cout << -1 << endl; return; }
  reverse(order.begin(), order.end());
  for(ll i = 0; i < order.size(); i++){
    cout << (i ? string(1,l_to_s[order[i]][k-2]) : l_to_s[order[i]]);
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