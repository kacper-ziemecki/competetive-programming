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


void solve()
{
	ll n, MOD = 1e9+7;
  cin >> n;
  vector<ll> dp(n+1,0);
  dp[0] = 1;
  for(ll i = 1; i <= n; i++){
    for(ll j = i-1; j >= max(0ll,i-6); j--){
      dp[i] += dp[j];
      dp[i] %= MOD;
    }
  }
  cout << dp[n] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}