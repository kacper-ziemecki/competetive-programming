#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n;
	cin >> n;
	vector<ll> list(n, 0), dp(n, INT_MIN);
	for(auto &el : list) cin >> el;
	for(ll i = 0; i < n; i++){
		ll temp = INT_MIN;
		if(i >= 1) temp = max(temp, dp[i-1] + list[i]);
		if(i >= 2) temp = max(temp, dp[i-2] + list[i]);
		if(i >= 3) temp = max(temp, dp[i-3] + list[i]);
		if(i >= 4) temp = max(temp, dp[i-4] + list[i]);
		if(i >= 5) temp = max(temp, dp[i-5] + list[i]);
		if(i >= 6) temp = max(temp, dp[i-6] + list[i]);
		if(i == 0) temp = list[i];

		dp[i] = temp;
	}
	cout << dp[n-1] << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  solve();
}