#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int x, y, k;
  cin >> x >> y >> k;
  cout << (max(x, y) - min(x, y) - 1 + k) / k << "\n";
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