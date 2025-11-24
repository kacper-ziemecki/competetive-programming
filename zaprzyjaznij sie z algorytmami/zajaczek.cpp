#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  n++;
  vector<ll> list(n, 0);
  for(auto & el : list) cin >> el;
  vector<ll> dp(n, INT_MAX);
  vector<ll> fib = {0, 1};

  while(fib[fib.size()-2] + fib.back() < 300001){
    fib.push_back(fib[fib.size()-2] + fib.back());
  }

  if(list[0] == 1 || list.back() == 1){
    cout << -1 << endl;
    return;
  }
  dp[0] = 0;
  for(ll i = 1; i < n; i++){
    if(list[i] == 1) dp[i] = -1;
    ll j = 1;
    while(j < fib.size() && (i - fib[j]) >= 0){
      dp[i] = min(dp[i], (list[i - fib[j]] == 0 ? dp[i - fib[j]] + 1 : INT_MAX));
      j++;
    }
  }
  // for(auto el : dp) cout << el << " ";
  // cout << endl;
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