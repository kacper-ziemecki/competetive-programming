#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m)
{
  vector<string> list(n, "");
  for (auto &el : list)
    cin >> el;
  long double res = 0;
  bool flag = false;
  for (ll i = 0; i < n; i++)
  {
    flag = false;
    for (ll j = 0; j < m; j++)
    {
      if (list[i][j] != '.')
        res += 0.5;

      if (list[i][j] == '.' && flag)
        res++;

      if ((!flag && list[i][j] == '/') || (!flag && list[i][j] == '\\'))
      {
        flag = true;
      }
      else if ((flag && list[i][j] == '/') || (flag && list[i][j] == '\\'))
      {
        flag = false;
      }
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

  ll n, m;
  while (cin >> n >> m)
    solve(n, m);
}