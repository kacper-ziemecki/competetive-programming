#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll k, ll m)
{
  unordered_map<ll, bool> list{};
  ll temp;
  for (ll i = 0; i < k; i++)
  {
    cin >> temp;
    list[temp] = true;
  }
  ll c, r;
  bool flag = true;
  for (ll i = 0; i < m; i++)
  {
    cin >> c >> r;
    for (ll j = 0; j < c; j++)
    {
      cin >> temp;
      if (list[temp])
        r--;
    }
    if (r > 0 && flag)
    {
      cout << "no\n";
      flag = false;
    }
  }
  if (flag)
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

  ll k, m;
  while (cin >> k >> m)
    solve(k, m);
}