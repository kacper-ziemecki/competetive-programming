#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll i)
{
  ll a, b, c;
  cin >> a >> b >> c;
  if (a > 20 || b > 20 || c > 20)
  {
    cout << "Case " << i << ": bad\n";
  }
  else
  {
    cout << "Case " << i << ": good\n";
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
  for (ll i = 1; i <= t; i++)
    solve(i);
}