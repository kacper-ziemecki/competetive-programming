#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  string one, two;
  cin >> one >> two;
  ll res = 0;
  for (auto el : one)
  {
    if (el == '?')
      res++;
  }
  ll first = 0, second = 0, total1 = 0, total2 = 0;
  for (ll i = 0; i < one.size(); i++)
  {
    if (one[i] == '0' && two[i] == '1')
      first++;
    if (one[i] == '1' && two[i] == '0')
      second++;
    if (one[i] == '1')
      total1++;
    if (two[i] == '1')
      total2++;
  }
  if (second == 0)
  {
    res += first;
  }
  else if (total1 > total2)
  {
    cout << "Case " << test << ": " << -1 << endl;
    return;
  }
  else
  {
    res += max(first, second);
    cout << "Case " << test << ": " << res << endl;
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