#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int a, b;
  cin >> a >> b;
  if (min(a, b) * 2 >= max(a, b))
  {
    cout << min(a, b) * 2 * min(a, b) * 2 << endl;
  }
  else
  {
    cout << max(a, b) * max(a, b) << endl;
  }
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