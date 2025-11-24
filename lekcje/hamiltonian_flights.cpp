#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,u,v;
const ll maxN = 21, maxM = maxN*maxN, MOD = 1e9+7;
ll dp[1<<maxN][maxN];
vector<ll> adj[maxN];

void solve()
{
  cin >> n >> m;
  for(ll i = 0; i < m; i++){
    cin >> u >> v;
    adj[v].pb(u);
  }
  dp[1][1] = 1;
  for(ll mask = 2; mask < (1<<n); mask++){
    if(mask & 1 == 0 || ((mask & (1<<(n-1))) && (mask != (1<<n)-1))) continue;
    for(ll u = 1; u <= n; u++){
      if(mask & (1<<(u-1)) == 0) continue;
      for(auto v : adj[u]){
        if(mask & (1<<(v-1)) == 0) continue;
        dp[mask][u] += dp[mask^(1<<(u-1))][v];
        if(dp[mask][u] > MOD) dp[mask][u] %= MOD;
        // if(dp[mask][u]) dbg(to_bits(mask), to_bits(mask^(1<<(u-1))), u, v, dp[mask][u]);
      }
    }
  }
  cout << dp[(1<<n)-1][n] % MOD << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

 
}