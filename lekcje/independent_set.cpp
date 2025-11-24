#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n, MOD = 1e9+7;
const ll maxN = 1e5+1;
vector<ll> adj[maxN];
ll dp[maxN][2];

ll dfs(ll u, ll color, ll p){
  if(dp[u][color] != -1) return dp[u][color];
  dp[u][color] = 1;
  for(auto v : adj[u]){
    if(v == p) continue;
    if(color){
      dp[u][color] *= dfs(v,0,u);
    } else{
      dp[u][color] *= dfs(v,1,u)+dfs(v,0,u);
    }
    dp[u][color] %= MOD;
  }
  dp[u][color] %= MOD;
  return dp[u][color];
}

void solve()
{
  cin >> n;
  for(ll i = 0; i <= n; i++){
    dp[i][0] = -1; dp[i][1] = -1;
  }
  ll u,v;
  for(ll i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << (dfs(1, 0, -1)+dfs(1, 1, -1)) % MOD << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}