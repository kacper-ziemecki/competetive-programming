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
    cin >> el;
  for (int i = 0; i < n; i++)
  {
    if (list[i] % 2 == 0)
    {
      cout << 1 << endl
           << i + 1 << endl;
      return;
    }
    if (i + 1 < n && (list[i] + list[i + 1]) % 2 == 0)
    {
      cout << 2 << endl
           << i + 1 << " " << i + 2 << endl;
      return;
    }
  }
  cout << -1 << endl;
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