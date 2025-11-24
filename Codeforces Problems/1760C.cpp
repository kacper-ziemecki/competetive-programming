#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  pair<ll, ll> maks1 = {INT_MIN, 0}, maks2 = {INT_MIN, 0};
  vector<ll> list(n, 0);
  for (auto &el : list)
    cin >> el;
  ll i = -1;
  for (auto el : list)
  {
    i++;
    if (el > maks1.first)
    {
      maks2.first = maks1.first;
      maks2.second = maks1.second;
      maks1.first = el;
      maks1.second = i;
    }
    else if (el > maks2.first)
    {
      maks2.first = el;
      maks2.second = i;
    }
  }
  i = -1;
  for (auto el : list)
  {
    i++;
    if (i == maks1.second)
    {
      cout << el - maks2.first << " ";
    }
    else
    {
      cout << el - maks1.first << " ";
    }
  }
  cout << endl;
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