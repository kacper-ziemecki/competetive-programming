#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void process(ll u, vector<bool>& vis, vector<vector<pair<ll,ll>>>& adj, priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>& pq){
  vis[u] = true;
  for(auto [w, v] : adj[u]){
    if(!vis[v]) pq.emplace(w,v);
  }
}

void solve(ll n, ll m){
  map<string, ll> to;
  string s1,s2;
  ll a;
  for(ll i = 0; i < n; i++){
    cin >> s1;
    to[s1] = i;
  }
  vector<vector<pair<ll,ll>>> adj(n);
  vector<bool> vis(n, false);
  priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
  for(ll i = 0; i < m; i++){
    cin >> s1 >> s2 >> a;
    adj[to[s1]].push_back({a, to[s2]});
    adj[to[s2]].push_back({a, to[s1]});
  }
  // for(ll i = 0; i < adj.size(); i++){
  //   cout << i << ": ";
  //   for(ll j = 0; j < adj[i].size(); j++){
  //     cout << adj[i][j].first << "," << adj[i][j].second << " ";
  //   }
  //   cout << endl;
  // }
  cin >> s1;
  process(to[s1], vis, adj, pq);
  ll cnt=0, res=0;
  while(!pq.empty()){
    auto [w, u] = pq.top(); pq.pop();
    if(vis[u]) continue;
    process(u, vis, adj, pq);
    res += w;
    cnt++;
    if(cnt == n-1) break;
  }
  if(cnt < n-1){
    cout << "Impossible\n";
  } else{
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

  ll n,m;
  while(cin >> n >> m, n != 0 || m != 0) solve(n,m);
}