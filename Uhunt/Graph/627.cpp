#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll n){
  cout << "-----\n";
  map<ll, vector<ll>> adj;
  string s,cur;
  for(ll i = 0; i < n; i++){
    getline(cin>>ws, s);
    vector<ll> list;
    for(ll j = 0; j < s.size(); j++){
      if(s[j] >= '0' && s[j] <= '9') cur += s[j];
      else{
        list.push_back(stoll(cur));
        cur.clear();
      }
    }
    if(!cur.empty()){
      list.push_back(stoll(cur));
      cur.clear();
    }
    for(ll j = 1; j < list.size(); j++) adj[list[0]].push_back(list[j]);
  }
  ll m,u,v;
  cin >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;

    map<ll, bool> vis;
    map<ll, ll> parent;
    queue<ll> q;
    vis[u]=true;
    q.push(u);
    while(!q.empty()){
      ll p = q.front(); q.pop();
      for(auto v : adj[p]){
        if(!vis[v]){
          vis[v]=true;
          parent[v] = p;
          q.push(v);
        }
      }
    }
    if(vis.count(v) == 0){
      cout << "connection impossible\n";
    } else{
      vector<ll> res;
      ll k=0;
      while(v != u){
        if(k++ > 5) break;
        res.push_back(v);
        v = parent[v];
      }
      res.push_back(u);
      reverse(res.begin(), res.end());
      for(ll i = 0; i < res.size(); i++){
        if(i!=0) cout << " ";
        cout << res[i];
      }
      cout << endl;
    }
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

  ll n;
  while(cin>>n, !cin.eof()) solve(n);
}