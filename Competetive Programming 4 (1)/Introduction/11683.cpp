#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m)
{
  ll prev, cur, temp;
  cin >> cur;
  ll res = n - cur;
  for (ll i = 1; i < m; i++)
  {
    cin >> temp;
    prev = cur;
    cur = temp;
    if (cur < prev)
    {
      res += prev - cur;
    }
  }
  cout << res << endl;
}

int main()
{

  ll n, m;
  while (cin >> n >> m)
    solve(n, m);
}