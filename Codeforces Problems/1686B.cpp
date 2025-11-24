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
  ll i = 0;
  ll res = 0;
  for (; i < n - 1; i++)
  {
    if (list[i] > list[i + 1])
    {
      res++;
      i++;
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
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while (t--)
    solve();
}