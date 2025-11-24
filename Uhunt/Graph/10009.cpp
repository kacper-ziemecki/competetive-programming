#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,m;
  cin >> n >> m;
  map<string, vector<string>> adj;
  string u,v;
  for(ll i = 0; i < n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // for(auto el : adj){
  //   cout << el.first << ": ";
  //   for(auto sub : el.second) cout << sub << " ";
  //   cout << endl;
  // }
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    map<string, bool> vis;
    map<string, ll> dist;
    map<string, string> parent;
    queue<string> q;
    vis[u]=true;
    dist[u]=0;
    q.push(u);
    while(!q.empty()){
      string p = q.front(); q.pop();
      for(auto c : adj[p]){
        if(!vis[c]){
          vis[c] = true;
          dist[c] = dist[p]+1;
          parent[c] = p;
          q.push(c);
        }
      }
    }
    // cout <<"parent:\n";
    // for(auto el : parent) cout << el.first << " " << el.second << endl;
    string res(1,v[0]);
    while(v != u){
      v = parent[v];
      res += v[0];
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
  }
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

  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    if(i!=0) cout<<endl;
    solve();
  }
}