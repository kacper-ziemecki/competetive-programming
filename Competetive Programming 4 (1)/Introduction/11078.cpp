#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0), prefix(n, 0);
  for (auto &el : list)
    cin >> el;
  prefix[0] = list[0];
  for (ll i = 1; i < n; i++)
  {
    prefix[i] = max(prefix[i - 1], list[i]);
  }
  ll res = INT_MIN;
  for (ll i = 1; i < n; i++)
  {
    res = max(res, prefix[i - 1] - list[i]);
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while (t--)
    solve();
}