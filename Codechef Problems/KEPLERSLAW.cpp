#include <bits/stdc++.h>
using namespace std;

void solve()
{
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a * a) / (c * c * c) == (b * b) / (d * d * d))
    cout << "Yes\n";
  else
    cout << "No\n";
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