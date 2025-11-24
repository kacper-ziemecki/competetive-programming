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

ll n,k;
const ll maxN = 101, maxK = 1e5+1, MOD=1e9+7;
ll candies[maxN];
ll dp[maxK][maxN], prefixSum[maxK][maxN];

void solve()
{
  cin >> n >> k;
  for(ll i = 0; i < n; i++) cin >> candies[i];
  for(ll i = 0; i <= k; i++){
    for(ll j = 0; j <= n; j++){
      dp[i][j] = 1;
      prefixSum[i][j] = dp[i][j] + (i-1 >= 0 ? prefixSum[i-1][j] : 0);
      prefixSum[i][j] %= MOD;
    }
  }
  for(ll rest = candies[0]+1; rest <= k; rest++){
    dp[rest][0] = 0;
    prefixSum[rest][0] = (dp[rest][0] + (rest-1 >= 0 ? prefixSum[rest-1][0] : 0)) % MOD;
  }
  for(ll rest = 1; rest <= k; rest++){
    for(ll id = 1; id < n; id++){
      dp[rest][id] = ((prefixSum[rest][id-1] - (rest-min(rest,candies[id])-1 >= 0 ? prefixSum[rest-min(rest,candies[id])-1][id-1] : 0ll)) % MOD + MOD) % MOD;
      prefixSum[rest][id] = ((dp[rest][id] + prefixSum[rest-1][id]) % MOD + MOD) % MOD;
    }
  }
  cout << dp[k][n-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}