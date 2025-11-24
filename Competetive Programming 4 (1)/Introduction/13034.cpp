#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll i)
{
  vector<ll> list(13, 0);
  bool flag = true;
  for (auto &el : list)
  {
    cin >> el;
    if (el == 0)
      flag = false;
  }
  if (!flag)
  {
    cout << "Set #" << i << ": No\n";
  }
  else
  {
    cout << "Set #" << i << ": Yes\n";
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