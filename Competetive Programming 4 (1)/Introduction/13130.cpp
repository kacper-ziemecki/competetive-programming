#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  vector<ll> list(5, 0);
  for (auto &el : list)
    cin >> el;
  for (ll i = 1; i < list.size(); i++)
  {
    if (list[i] - 1 != list[i - 1])
    {
      cout << "N\n";
      return;
    }
  }
  cout << "Y\n";
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