#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n;
  cin >> n;
  int two = 0, one = 0;
  int temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp == 1)
      one++;
    else
      two++;
  }
  if ((two * 2 + one) % 2 == 0 && one > 0)
  {
    cout << "YES\n";
  }
  else if (one == 0 && (two % 2 == 0))
  {
    cout << "YES\n";
  }
  else
    cout << "NO\n";
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