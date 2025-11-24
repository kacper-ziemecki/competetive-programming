#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  cout << (2 * (180 + n) - (a + b)) << "\n";
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