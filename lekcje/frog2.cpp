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
const ll maxN = 1e5+1;
ll h[maxN], dp[maxN];

void solve()
{
  cin >> n >> k;
  for(ll i = 0; i < n; i++) cin >> h[i];
  fill(dp, dp+n, LLONG_MAX);
  dp[0]= 0;
  for(ll i = 1; i < n; i++){
    for(ll j = 1; j <= k; j++){
      if(i-j < 0) break;
      dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
    }
  }
  cout << dp[n-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}