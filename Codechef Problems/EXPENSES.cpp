#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  cin >> a >> b;
  long long res = 0;
  for (int i = 0; i < b - a + 1; i++)
  {
    if (!res)
      res = 1;
    else
      res *= 2;
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}