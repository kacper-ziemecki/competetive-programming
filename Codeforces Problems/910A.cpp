#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll a, b;
  cin >> a >> b;
  string text;
  cin >> text;
  ll index = 0;
  ll res = 0;
  while (true)
  {
    if (index == a - 1)
    {
      cout << res << endl;
      return;
    }
    bool flag = false;
    for (ll i = index + b; i > index; i--)
    {
      if (i < a && text[i] == '1')
      {
        index = i;
        res++;
        flag = true;
      }
    }
    if (!flag)
    {
      cout << -1 << endl;
      return;
    }
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

  solve();
}