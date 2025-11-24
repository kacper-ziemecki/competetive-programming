#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n;
  cin >> n;
  int i = 0, j = 0, x = 0;
  while (n)
  {
    x++;
    if (x < 4)
    {
      i += n % 10;
    }
    else
    {
      j += n % 10;
    }
    n /= 10;
  }
  cout << (i == j ? "YES\n" : "NO\n");
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
    solve();
}