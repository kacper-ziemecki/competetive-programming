#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m;
ll mod = 1e9+7;
const ll maxn = 1e5+1, maxm = 101;
ll dp[maxn][maxm];
ll lista[maxn];

void solve()
{
  cin >> n >> m;
  for(ll i = 0; i < n; i++){
    cin >> lista[i];
  }
  if(lista[0] == 0){
    for(ll i = 1; i <= m; i++) dp[0][i] = 1;
  } else{
    dp[0][lista[0]] = 1;
  }
  for(ll i = 1; i < n; i++){
    if(lista[i] == 0){
      for(ll cur = 1; cur <= m; cur++){
        dp[i][cur] = dp[i-1][cur] % mod;
        if(cur-1 > 0) dp[i][cur] = (dp[i][cur]+dp[i-1][cur-1]) % mod;
        if(cur+1 <= m) dp[i][cur] = (dp[i][cur]+dp[i-1][cur+1]) % mod;
      }
    } else{
      dp[i][lista[i]] = dp[i-1][lista[i]] % mod;
      if(lista[i]-1 > 0) dp[i][lista[i]] = (dp[i][lista[i]]+dp[i-1][lista[i]-1]) % mod;
      if(lista[i]+1 <= m) dp[i][lista[i]] = (dp[i][lista[i]]+dp[i-1][lista[i]+1]) % mod;
    }
  }
  ll res = 0;
  for(ll i = 1; i <= m; i++){
    res = (res + dp[n-1][i]) % mod;
  }
  cout << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();

}