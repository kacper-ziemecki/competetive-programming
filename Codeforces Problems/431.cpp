#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string text;
  cin >> text;
  int res = 0;
  for (auto el : text)
  {
    if (el == '1')
    {
      res += a;
    }
    else if (el == '2')
    {
      res += b;
    }
    else if (el == '3')
    {
      res += c;
    }
    else
    {
      res += d;
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

  solve();
}