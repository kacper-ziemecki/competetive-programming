#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const int MOD = 1e9+7, maxN = 101, maxSum = 1e6+1;
int dp[maxSum], coins[maxN];
int n,x;


void solve()
{
	cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> coins[i];
  for(int i = 0; i <= x; i++) dp[i] = 0;
  dp[0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = coins[i]; j <= x; j++){
      dp[j] += dp[j-coins[i]];
      dp[j] %= MOD;
    }
  }
  cout << dp[x] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}