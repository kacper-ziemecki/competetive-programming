#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0), dp(n+1, 0);
  for(auto &el : list) cin >> el;
  for(ll i = 0; i < n; i++){
    dp[min(n, list[i] + i)] = max(dp[min(n, list[i] + i)], list[i] + dp[i]);
  }
  cout << dp[n] << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}