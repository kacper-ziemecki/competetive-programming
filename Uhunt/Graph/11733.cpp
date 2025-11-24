#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void process(ll u, vector<vector<pair<ll,ll>>>& adj, vector<bool>& vis, priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >& pq){
  vis[u] = true;
  for(auto [w, v] : adj[u]){
    if(!vis[v]) pq.emplace(w, v);
  }
}

void solve(){
  ll n,m,a;
  cin >> n >> m >> a;
  vector<tuple<ll,ll,ll>> edges(m);
  vector<vector<pair<ll,ll>>> adj(n);
  vector<bool> vis(n, false);
  priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
  for(auto &edge : edges){
    cin >> get<1>(edge) >> get<2>(edge) >> get<0>(edge);
    get<1>(edge)--;
    get<2>(edge)--;
    adj[get<1>(edge)].push_back({get<0>(edge), get<2>(edge)});
    adj[get<2>(edge)].push_back({get<0>(edge), get<1>(edge)});
  }
  ll cnt1=0, cnt2=0;
  for(ll i = 0; i < n; i++){
    if(!vis[i]){
      process(i, adj, vis, pq);
      while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        
        if(w >= a) cnt1++;
        else cnt2 += w;
        process(u, adj, vis, pq);
      }
      cnt1++;
    }
  }
  cout << cnt2 + cnt1*a << " " << cnt1 << endl;
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
  for(ll i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
}