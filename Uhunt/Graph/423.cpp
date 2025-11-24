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
  vector<vector<pair<ll,ll>>> adj(n);
  vector<ll> dist(n, LLONG_MAX);
  priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
  ll w;
  string s;
  for(ll i = 1; i < n; i++){
    for(ll j = 0; j < i; j++){
      cin >> s;
      if(s[0] == 'x') continue;
      w = stoll(s);
      adj[i].push_back({j, w});
      adj[j].push_back({i, w});
    }
  }
  dist[0] = 0;
  pq.emplace(0,0);
  ll i=0;
  while(!pq.empty()){
    auto [w1, u] = pq.top(); pq.pop();
    for(auto [v, w2] : adj[u]){
      if(dist[v] > w1+w2){
        dist[v] = w1+w2; 
        pq.push({dist[v], v});
      }
    }
  }
  ll mx=0;
  for(auto el : dist) mx = max(mx, el);
  cout << mx << endl;
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
  while(cin >> n, !cin.eof())
  solve(n);
  
}