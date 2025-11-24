#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  long double a, b;
  cin >> a >> b;
  cout << "Case " << test << ": ";
  cout << fixed << setprecision(2);
  cout << a + ((5 * (b)) / 9) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++)
    solve(i);
}