#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  for (auto el : text)
  {
    if (el == 'Z')
    {
      cout << 0 << endl;
      return;
    }
  }
  ll one = -1, two = -1;
  ll res = INT_MAX;
  for (ll i = 0; i < text.size(); i++)
  {
    if (text[i] == 'D')
    {
      one = i;
    }
    else if (text[i] == 'R')
    {
      two = i;
    }
    if (one != -1 && two != -1)
      res = min(res, abs(one - two));
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

  ll n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    solve();
  }
}