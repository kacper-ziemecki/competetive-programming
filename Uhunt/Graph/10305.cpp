#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(ll n, ll m){
  vector<unordered_set<ll>> adj(n+1);
  vector<ll> in_degree(n+1, 0);
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll v,u;
  for(ll i = 0; i < m; i++){
    cin >> v >> u;
    adj[v].emplace(u);
    in_degree[u]++;
  }
  for(ll i = 1; i < n+1; i++) if(in_degree[i] == 0) pq.push(i);
  while(!pq.empty()){
    ll i = pq.top(); pq.pop();
    cout << i << " ";
    for(auto j : adj[i]){
      if(--in_degree[j] == 0) pq.push(j);
    }
  }
  cout << endl;
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


  ll n,m;
  cin >> n >> m;
  while(n != 0 && m != 0){
    solve(n,m);
    cin >> n >> m;
  }
}