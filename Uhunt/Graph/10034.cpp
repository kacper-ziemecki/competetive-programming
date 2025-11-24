#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


// vector<vector<ll>> adj;
// vector<bool> vis;
// priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>()> pq;

// void process(ll u){
//   taken[u] = true;
//   for(auto &[v,w] : adj[u]){
//     if(!taken[v]) pq.emplace(w, v);
//   }
// }

priority_queue<pair<ld,ld>, vector<pair<ld,ld>>, greater<pair<ld,ld>>> pq;
vector<pair<ld,ld>> lista;
vector<bool> vis;

void process(ll i){
  vis[i] = true;
  for(ll j = 0; j < lista.size(); j++){
    if(i==j)continue;
    pq.emplace(sqrt((lista[i].first-lista[j].first)*(lista[i].first-lista[j].first)+(lista[i].second-lista[j].second)*(lista[i].second-lista[j].second)), j);
  }
}

void solve(){
  ll n,cnt=0;
  ld res=0;
  cin >> n;
  while(!pq.empty()) pq.pop();
  lista.assign(n, {0.0, 0.0});
  vis.assign(n, false);
  for(auto &el : lista) cin >> el.first >> el.second;
  // for(auto el : lista) cout << el.first << " " << el.second << endl;
  process(0);
  while(!pq.empty()){
    auto el = pq.top(); pq.pop();
    ld w = el.first;
    ld u = el.second;
    if(vis[u]) continue;
    res += w;
    cnt++;
    if(cnt == n-1) break;
    process(u);
  }
  cout << fixed << setprecision(2) << res << endl;
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


  ll t,i=0;
  cin >> t;
  while(t--){
    if(i++ != 0) cout << endl;
    solve();
  }
}