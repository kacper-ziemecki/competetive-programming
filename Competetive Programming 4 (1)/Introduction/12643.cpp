#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll a, ll b, ll c)
{
  ll temp = 1, one, two;
  for (ll i = 1; i <= a; i++)
  {
    temp *= 2;
    one = (b + temp - 1) / temp;
    two = (c + temp - 1) / temp;
    if (one == two)
    {
      cout << i << endl;
      return;
    }
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

  ll a, b, c;
  while (cin >> a >> b >> c)
    solve(a, b, c);
}