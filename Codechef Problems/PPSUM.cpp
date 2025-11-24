#include <bits/stdc++.h>
using namespace std;

int subsolve(int a, int b)
{
  return b == 0 ? a : subsolve((a * (a + 1)) / 2, b - 1);
}

void solve()
{
  int a, b;
  cin >> a >> b;
  cout << subsolve(b, a) << "\n";
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