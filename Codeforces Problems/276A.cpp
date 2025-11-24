#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> list(n, { 0, 0 });
  for (auto& el : list) cin >> el.first >> el.second;
  ll res;
  if (list[0].second > k) {
    res = list[0].first - (list[0].second - k);
  }
  else {
    res = list[0].first;
  }
  for (auto el : list) {
    if (el.second > k) {
      res = max(res, el.first - (el.second - k));
    }
    else {
      res = max(res, el.first);
    }
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