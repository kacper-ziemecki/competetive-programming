#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll t)
{
  ll a, b, c;
  cin >> a >> b >> c;
  for (ll i = 0; i < c; i++)
  {
    b++;
    if (b == a + 1)
      b = 1;
  }
  cout << "Case " << t << ": " << b << endl;
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
  for (ll i = 1; i <= t; i++)
    solve(i);
}