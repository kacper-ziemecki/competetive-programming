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
  map<string, vector<string>> adj;
  string u,v,s,d;
  for(ll i = 0; i < n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> s >> d;
  queue<string> q;
  map<string,ll> dist;
  map<string,string> p;
  map<string,bool> vis;
  q.push(s);
  dist[s]=0;
  vis[s]=true;
  while(!q.empty()){
    u=q.front();q.pop();
    for(auto v : adj[u]){
      if(!vis[v]){
        p[v]=u;
        vis[v]=true;
        q.push(v);
        dist[v]=dist[u]+1;
      }
    }
  }
  string road = d;
  vector<string> res;
  bool flag=true;
  while(road != s){
    res.push_back(road);
    if(p.count(road)==0){
      flag=false;break;
    }
    road = p[road];
  }
  res.push_back(s);
  if(!flag){
    cout << "No route\n";
  } else{
    for(ll i = res.size()-1; i > 0; i--){
      cout << res[i] << " " << res[i-1] << endl;
    }
  }
  // cout << endl;
  // cout << dist[d] << endl;
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
  ll i = 0;
  while(cin>>n, !cin.eof()){
    if(i++ != 0) cout << endl;
    solve(n);
  }
}