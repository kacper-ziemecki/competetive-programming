#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, p;
  cin >> n >> p;
  vector<ll> list(p, 0);
  for (auto &el : list)
    cin >> el;
  vector<bool> res(n + 1, false);
  for (auto el : list)
  {
    ll temp = el;
    while (temp <= n)
    {
      if ((temp >= 6 && (temp - 6) % 7 == 0) || (temp >= 7 && (temp - 7) % 7 == 0))
      {
        temp += el;
        continue;
      }
      res[temp] = true;
      temp += el;
    }
  }
  ll ans = 0;
  for (auto el : res)
  {
    if (el)
      ans++;
  }

  cout << ans << endl;
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