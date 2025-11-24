#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a = 0, b = 0, c;
  for (int i = 0; i < 10; i++)
  {
    cin >> c;
    if (i & 1 && c == 1)
      a++;
    else if (!(i & 1) && c == 1)
      b++;
  }
  cout << (a > b ? 2 : (b == a ? 0 : 1)) << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}