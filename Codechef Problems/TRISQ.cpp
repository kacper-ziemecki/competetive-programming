#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  n -= 3;
  if ((n & 1))
    n++;
  n /= 2;
  n++;
  cout << (n * (n - 1)) / 2 << "\n";
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