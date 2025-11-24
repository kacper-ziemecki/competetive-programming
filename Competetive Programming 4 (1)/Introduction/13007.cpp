#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m)
{
  ll res = 0;
  ll temp;
  ll maks;
  ll a, b;
  vector<ll> list = {1, 10, 100, 1000, 10000};
  for (ll i = 0; i < m; i++)
  {
    cin >> a >> b;
    ll suma = 0;
    for (ll j = 0; j < n - 1; j++)
    {
      cin >> temp;
      suma += temp;
    }
    temp = (a >= b + suma ? b : 0);
    maks = 0;
    for (auto el : list)
    {
      maks = max(maks, (a >= (el + suma) ? el : 0));
    }
    res += maks - temp;
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

  ll n, m;
  while (cin >> n >> m)
    solve(n, m);
}