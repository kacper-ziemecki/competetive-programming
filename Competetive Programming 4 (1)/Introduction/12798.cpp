#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m)
{
  ll res = 0;
  ll temp;
  for (ll i = 0; i < n; i++)
  {
    bool flag = true;
    for (ll j = 0; j < m; j++)
    {
      cin >> temp;
      if (temp == 0)
        flag = false;
    }
    res += flag;
  }
  cout << res << endl;
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

  ll n, m;
  while (cin >> n >> m)
    solve(n, m);
}