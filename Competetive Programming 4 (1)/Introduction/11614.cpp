#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  // cout << sqrt(2 * n) << endl;
  if ((ll)sqrt(2 * n) * (ll)(sqrt(2 * n) + 1) <= 2 * n)
  {
    cout << (ll)sqrt(2 * n) << endl;
  }
  else
  {
    cout << (ll)sqrt(2 * n) - 1 << endl;
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