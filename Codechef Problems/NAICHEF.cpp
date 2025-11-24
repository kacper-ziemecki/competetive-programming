#include <bits/stdc++.h>
using namespace std;

void solve()
{
  double n, a, b, jeden = 0, dwa = 0, tmp;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    if (tmp == a)
      jeden++;
    if (tmp == b)
      dwa++;
  }
  cout << fixed;
  cout << (jeden / n) * (dwa / n) << "\n";
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