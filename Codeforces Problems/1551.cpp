#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  int n;
  cin >> n;
  if (n % 3 == 0)
  {
    cout << n / 3 << " " << n / 3 << endl;
  }
  else if (n % 3 == 1)
  {
    cout << (n - 1) / 3 + 1 << " " << (n - 1) / 3 << endl;
  }
  else
  {
    cout << (n - 2) / 3 << " " << (n - 2) / 3 + 1 << endl;
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