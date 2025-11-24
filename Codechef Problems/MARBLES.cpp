#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  cin >> a >> b;
  long long res = 1;
  for (int i = b + 1; i < a - b; i++)
  {
    res *= i;
  }
  res *= (a - b);
  cout << res << "\n";
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