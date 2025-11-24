#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a % c == 0 && b % c == 0 ? "YES\n" : "NO\n");
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