#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n, ll m)
{
  vector<vector<ll>> list(m, vector<ll>(n, 0));
  for (auto& sub : list) {
    for (auto& el : sub) cin >> el;
  }
  vector<ll> res(n, 0);
  ll maks = 0;
  for (auto sub : list) {
    for (ll i = 0; i < n; i++) {
      res[i] += sub[i];
      maks = max(maks, res[i]);
    }
  }
  for (ll i = n - 1; i >= 0; i--) {
    if (res[i] == maks) {
      cout << i + 1 << endl;
      return;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll n, m;
  while (cin >> n >> m) {
    solve(n, m);
  }
}