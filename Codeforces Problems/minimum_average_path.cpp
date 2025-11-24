#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

pair<bool, vector<ll>> check(vector<vector<pair<ll,ll>>>& adj, ll n, ll m, ll mid){
  
}

void solve()
{
  ll n,m,u,v,w;
  cin >> n >> m;
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(ll i = 0; i < m; i++){
    cin >> u >> v >> w;
    adj[u].push_back({u, w});
  }
  ld l = -10, r = 110, eps = 1e-3;
  vector<ll> ans;
  while(l+eps < r){
    ld mid = (l+r)/2.0;
    pair<bool, vector<ll>> res = check(adj,n,m,mid);
    if(res.first){
      l = mid;
      ans = res.second;
    } else{
      r = mid;
    }
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}