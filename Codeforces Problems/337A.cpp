#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> list(m, 0);
  for (auto& el : list) cin >> el;
  sort(list.begin(), list.end());
  ll res = LONG_LONG_MAX;
  for (ll i = 0; i + n - 1 < m; i++) {
    res = min(res, list[i + n - 1] - list[i]);
  }
  cout << res << endl;
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

  solve();
}