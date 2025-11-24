#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  cin >> a >> b;
  if (b == 1)
  {
    if (a % 4 == 0)
      cout << "On\n";
    else
      cout << "Ambiguous\n";
  }
  else
  {
    if (a % 4 == 0)
      cout << "Off\n";
    else
      cout << "On\n";
  }
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