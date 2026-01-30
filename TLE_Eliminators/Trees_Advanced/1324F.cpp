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

ll n;
ll u,v;
const ll N = 2e5+1;
ll color[N], subtree[N], ans[N];
vector<ll> adj[N];

void calc_first_ans(ll u, ll p){
  subtree[u] = (color[u] == 1 ? 1 : -1);
  for(auto v : adj[u]){
    if(v != p){
      calc_first_ans(v,u);
      subtree[u] += max(0ll, subtree[v]);
    }
  }
}

void calc_every_ans(ll u, ll p, ll answer){
  ans[u] = answer;
  for(auto v : adj[u]){
    if(v != p) calc_every_ans(v,u,subtree[v]+max(0ll,ans[u] - max(0ll,subtree[v])));
  }
}

void solve(){
  cin >> n;
  for(ll i = 1; i <= n; i++) cin >> color[i];
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  calc_first_ans(1,1);
  calc_every_ans(1,1,subtree[1]);
  for(ll i = 1; i <= n; i++) cout << ans[i] << ' ';
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

  
  solve();
}