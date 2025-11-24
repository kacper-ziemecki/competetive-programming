#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  vector<pair<ll, ll>> list(n, { 0ll, 0ll });
  for (auto& el : list) cin >> el.first >> el.second;
  vector<ll> res(n, -1);
  ll i = -1;
  for (auto el : list) {
    i++;
    if ((i + el.second < 0) || (i + el.second >= n)) {
      cout << -1;
      return;
    }
    if (res[i + el.second] != -1) {
      cout << -1;
      return;
    }
    res[i + el.second] = el.first;
  }
  for (ll i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i != res.size() - 1) cout << " ";
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

  ll n;
  ll i = 0;
  while (true) {
    i++;
    cin >> n;
    if (n == 0) break;
    if (i != 1) cout << endl;
    solve(n);
  }
}