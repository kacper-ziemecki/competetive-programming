#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  string one, two;
  cin >> one >> two;
  ll res = 0;
  for (ll i = 0; i < n; i++)
  {
    if (one[i] == '0' && two[i] == '1')
      res++;
    else if (two[i] == '1' && i > 0 && one[i - 1] == '1')
      res++;
    else if (two[i] == '1' && i < n - 1 && one[i + 1] == '1')
    {
      one[i + 1] = '0';
      res++;
    }
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}