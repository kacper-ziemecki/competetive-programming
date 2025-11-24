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

const int N = 5005;
int n, mod, dp[N][N], ans;

inline void add(int& x, int y){x += y;if (x >= mod) x -= mod;}

void solve()
{
  cin >> n >> mod;
  dp[0][0] = 1;
  ans = 0;

  for(int i = 1;i <= n;i++) 
    for(int j = 0;j <= i;j++) 
      dp[i][j] = 0;

  for(int i = 1;i <= n;i++){
    for(int j = 0, now;j < i;j++){
      if(now = dp[i - 1][j]){
        add(dp[i][j + 1], now);
        dp[i][j] = (dp[i][j] + (n - i + 1ll) * (j + 1) * now) % mod;
      }
    }
  }
  for (int j = 0;j <= n;j ++) 
    add(ans, dp[n][j]);

  cout << ans << endl;
} 
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}