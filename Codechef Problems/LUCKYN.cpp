#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string n;
  cin >> n;
  for (auto el : n)
  {
    if (el == '7')
    {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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