#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n;
  cin >> n;

  vector<ll> dp(n, 0);
  dp[1] = 3;
  ll pow = 3;
  for(ll i = 2; i < n; i++){
    pow *= 3;
    pow %= 1000000007;
    dp[i] = pow - dp[i-1];
    dp[i] %= 1000000007;
    if(dp[i] < 0) dp[i] += 1000000007;
    // dbg(pow, dp[i]);
  }
  cout << dp[n-1] << endl;
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