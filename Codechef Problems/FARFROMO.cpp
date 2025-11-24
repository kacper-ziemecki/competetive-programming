#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c, d;
  double jeden, dwa;
  cin >> a >> b >> c >> d;
  jeden = sqrt(a * a + b * b);
  dwa = sqrt(c * c + d * d);
  if (jeden == dwa)
  {
    cout << "EQUAL\n";
  }
  else if (jeden > dwa)
  {
    cout << "ALEX\n";
  }
  else
  {
    cout << "BOB\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}