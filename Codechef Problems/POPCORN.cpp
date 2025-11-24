#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << max(a + b, max(c + d, e + f)) << "\n";
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