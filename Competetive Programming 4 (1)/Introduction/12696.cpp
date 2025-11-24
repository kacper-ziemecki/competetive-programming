#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

ll solve()
{
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a <= 56 && b <= 45 && c <= 25 && d <= 7)
  {
    cout << 1 << endl;
    return 1;
  }
  else if (a + b + c <= 125 && d <= 7)
  {
    cout << 1 << endl;
    return 1;
  }
  cout << 0 << endl;
  return 0;
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
  ll res = 0;
  while (t--)
  {
    res += solve();
  }
  cout << res << endl;
}