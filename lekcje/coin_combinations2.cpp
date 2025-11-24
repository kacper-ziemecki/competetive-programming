#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll int
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,x,MOD=1e9+7;
vector<ll> coins;
const ll maxN = 101, maxX = 1e6+1;
ll dp[maxN][maxX];

ll helper(ll id, ll sum){
  if(sum == x) return 1;
  if(id >= coins.size() || sum > x) return 0;
  if(dp[id][sum] != -1) return dp[id][sum];
  dp[id][sum] = 0;
  for(ll i = 0; i*coins[id]+sum <= x; i++){
    dp[id][sum] += helper(id+1, sum+i*coins[id]);
    dp[id][sum] %= MOD;
  }
  return dp[id][sum];
}

void solve()
{
  cin >> n >> x;
  coins.resize(n);
  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= x; j++) dp[i][j] = -1;
  }
  for(auto &el : coins) cin >> el;
  for(ll id = 0; id < n; id++){
    for(ll sum = 0; sum <= x; sum++){
      for(ll curSum = sum-coins[id]; curSum >= 0; curSum-=coins[id]){
        dp[id][sum] += dp[i-1][curSum];
      }
    }
  }
  cout << helper(0, 0) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}