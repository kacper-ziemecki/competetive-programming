#include <bits/stdc++.h>
using namespace std;

void solve(int n, int &maks, int rest = 0)
{
  if (n + rest < maks)
    return;
  maks = max(maks, n + rest);
  solve(n / 2, maks, n / 3 + n / 4);
  solve(n / 3, maks, n / 2 + n / 4);
  solve(n / 4, maks, n / 2 + n / 3);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, res;
  while (cin >> n)
  {
    res = 0;
    solve(n, res);
    cout << res << "\n";
  }
}