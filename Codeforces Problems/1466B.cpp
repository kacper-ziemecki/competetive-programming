#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for (auto &el : list)
  {
    cin >> el;
  }
  ll res = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (i == n - 1)
    {
      list[i]++;
    }
    else if (i + 1 < n && list[i + 1] - list[i] >= 2)
    {
      list[i]++;
    }
  }
  // for (auto el : list)
  // {
  //   cout << el << " ";
  // }
  // cout << endl;
  for (int i = 1; i < n; i++)
  {
    if (list[i] != list[i - 1])
      res++;
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