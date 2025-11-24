#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  if (n % 7 == 0 && n % 10 != 0)
  {
    cout << n << endl;
    return;
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}