#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
void dfs(string u, map<string, bool> &vis, map< string, vector<string> > &adj, vector<string> &order){
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v]) dfs(v, vis, adj, order);
  } 
  order.push_back(u);
}
void dfs_inv(string u, map<string, bool> &vis, map< string, vector<string> > &adj_inv, map<ll, vector<string>> &colors, ll &cnt){
  vis[u] = true;
  for(auto v : adj_inv[u]){
    if(!vis[v]) dfs_inv(v, vis, adj_inv, colors, cnt);
  } 
  colors[cnt].push_back(u);
}

void solve(ll n, ll m, ll t){
  map<string, vector<string>> adj, adj_inv;
  string a,b;
  for(ll i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj_inv[b].push_back(a);
  }
  vector<string> order;
  map<ll, vector<string>> colors;
  map<string, bool> vis;
  ll cnt=0;
  for(auto u : adj){
    if(!vis[u.first]) dfs(u.first, vis, adj, order);
  }
  vis.clear();
  cnt = 0;
  for(ll i = order.size()-1; i >= 0; i--){
    if(!vis[order[i]]){ dfs_inv(order[i], vis, adj_inv, colors, cnt); cnt++; }
  }
  cout << "Calling circles for data set " << t << ":\n";
  for(auto el : colors){
    for(ll i = 0; i < el.second.size(); i++){
      cout << el.second[i];
      if(i != el.second.size()-1) cout << ", ";
    }
    cout << endl;
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
  
  ll n,m,t=0;
  cin >> n >> m;
  while(n != 0 && m != 0){
    t++;
    if(t>1) cout << endl;
    solve(n,m,t);
    cin >> n >> m;
  }
}