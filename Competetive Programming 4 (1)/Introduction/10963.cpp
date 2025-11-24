#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> list(n, {0, 0});
  for (auto &el : list)
    cin >> el.first >> el.second;
  for (ll i = 1; i < n; i++)
  {
    if (abs(list[i].first - list[i].second) != abs(list[i - 1].first - list[i - 1].second))
    {
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
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
  {
    solve();
    if (t > 0)
      cout << "\n";
  }
}