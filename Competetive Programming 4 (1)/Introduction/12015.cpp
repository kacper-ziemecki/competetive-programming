#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll i)
{
  vector<pair<ll, string>> list(10, {0ll, ""});
  ll maks = INT_MIN;
  for (auto &el : list)
  {
    cin >> el.second >> el.first;
    maks = max(maks, el.first);
  }

  cout << "Case #" << i << ":\n";
  for (auto el : list)
  {
    if (el.first == maks)
    {
      cout << el.second << endl;
    }
  }
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
  for (ll i = 1; i <= t; i++)
    solve(i);
}