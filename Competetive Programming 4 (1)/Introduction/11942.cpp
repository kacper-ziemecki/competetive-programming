#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  vector<ll> list(10, 0), sorted1, sorted2;
  for (auto &el : list)
    cin >> el;
  sorted1 = list;
  sorted2 = list;
  sort(sorted1.begin(), sorted1.end());
  sort(sorted2.rbegin(), sorted2.rend());
  bool flag1 = true, flag2 = true;
  for (ll i = 0; i < 10; i++)
  {
    if (list[i] != sorted1[i])
    {
      flag1 = false;
    }
  }
  for (ll i = 0; i < 10; i++)
  {
    if (list[i] != sorted2[i])
    {
      flag2 = false;
    }
  }
  if (flag1 || flag2)
  {
    cout << "Ordered\n";
  }
  else
  {
    cout << "Unordered\n";
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
  cout << "Lumberjacks:\n";
  while (t--)
    solve();
}