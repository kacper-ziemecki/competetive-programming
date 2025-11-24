#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


string solve(ll n){
  map<string, vector<string>> adj;
  map<string, ll> in_degree;
  map<string, bool> vis;
  vector<string> list(n);
  string topo;
  string u,v;
  ll m,cnt=0;
  for(ll i = 0; i < n; i++){
    cin >> u;
    list[i] = u;
    adj[u] = {};
    vis[u] = false;
  }
  cin >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    in_degree[v]++;
  }
  while(cnt < n){
    for(string u : list){
      if(in_degree[u] == 0 && !vis[u]){
        topo += u;
        if(cnt != n-1) topo += ' ';
        vis[u] = true;
        for(string v : adj[u]) in_degree[v]--;
        cnt++;
        break;
      }
    }
  }
  return topo + '.';
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
  for(ll t = 1; cin >> n; t++) cout << "Case #" << t << ": Dilbert should drink beverages in this order: " << solve(n) << endl << endl;
}