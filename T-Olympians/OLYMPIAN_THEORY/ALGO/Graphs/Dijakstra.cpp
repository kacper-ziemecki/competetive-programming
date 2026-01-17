#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,m;
int u,v,w;
vector<vector<pair<int,int>>> adj;

int dijakstra(int u, int v){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  vector<int> d(n+1, INT_MAX);
  d[u] = 0;
  pq.push(make_pair(0,u));
  while(!pq.empty()){
    pair<int,int> cur = pq.top();
    pq.pop();
    if(cur.first > d[cur.second]) continue;

    for(auto v : adj[cur.second]){
      if(d[v.first] > max(d[cur.second],v.second)){
        d[v.first] = max(d[cur.second],v.second);
        pq.push(make_pair(d[v.first], v.first));
      }
    }
  }
  return d[v];
}


int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  int u,v,w;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].pb(make_pair(v,w));
    adj[v].pb(make_pair(u,w));
  }

  priority_queue<pair<int,int>, vector<pair<int,int>, greater<>> pq;
  vector<int> d(n+1, INT_MAX);
  d[1] = 0;
  pq.push(make_pair(0,1));
  while(!pq.empty()){
    pair<int,int> cur = pq.top();
    pq.pop();
    if(cur.first > d[cur.second]) continue;

    for(int v : adj[cur.second]){
      int aktualny_dystans = v.second + d[cur.second];
      if(aktualny_dystans <= d[v.first]){
        d[v.first] = aktualny_dystans;
        pq.push(make_pair(d[v.first], v.second));
      }
    }
  }
}