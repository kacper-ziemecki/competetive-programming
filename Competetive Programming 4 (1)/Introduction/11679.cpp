#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m)
{
  vector<ll> list(n, 0);
  for (auto &el : list)
    cin >> el;
  ll a, b, c;
  for (ll i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    list[a - 1] -= c;
    list[b - 1] += c;
  }
  for (auto el : list)
  {
    if (el < 0)
    {
      cout << "N\n";
      return;
    }
  }
  cout << "S\n";
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
  while (true)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
}