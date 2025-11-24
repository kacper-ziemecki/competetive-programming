#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string napis;
  cin >> napis;
  int a = 0, b = 0;
  for (auto el : napis)
  {
    if (el == 'a')
      a++;
    else
      b++;
  }
  cout << min(napis.size() - a, napis.size() - b) << endl;
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