#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,u,v,total_suma,res;
const ll N = 2e5+1;
ll color[N], suma_color[N], cost[N];
vector<ll> adj[N];

ll calc_suma_color(ll u, ll p){
  suma_color[u] = color[u];
  for(auto v : adj[u]){
    if(v != p) suma_color[u] += calc_suma_color(v,u);
  }
  return suma_color[u];
}
ll calc_first_cost(ll u, ll p){
  for(auto v : adj[u]){
    if(v != p) cost[u] += suma_color[v] + calc_first_cost(v,u);
  }
  return cost[u];
}
void calc_every_cost(ll u, ll p, ll cur_cost){
  cost[u] = cur_cost;
  for(auto v : adj[u]){
    if(v != p) calc_every_cost(v,u,cur_cost - 2*suma_color[v] + total_suma);
  }
}
void solve(){
  cin >> n;
  for(ll i=1; i <= n; i++) cin >> color[i];
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  calc_suma_color(1,1);
  calc_first_cost(1,1);
  total_suma = suma_color[1];
  calc_every_cost(1,1,cost[1]);
  for(ll i = 1; i <= n; i++) res = max(res, cost[i]);
  cout << res << endl;
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

  
  solve();
}