#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c, d, temp;
  cin >> a >> b >> c >> d;
  temp = a;
  if (a >= b)
    b += c;
  else
    a += c;
  if (a >= b)
    b += d;
  else
    a += d;

  if (a >= b)
    cout << "N\n";
  else
    cout << "S\n";
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