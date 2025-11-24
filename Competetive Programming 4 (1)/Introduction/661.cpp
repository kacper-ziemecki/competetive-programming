#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll m, ll c, ll test1)
{

  vector<ll> list(n, 0);
  vector<bool> test(n, false);

  for (auto &el : list)
  {
    cin >> el;
  }

  ll maks = 0;
  ll cur = 0;
  ll temp;

  for (ll i = 0; i < m; i++)
  {
    cin >> temp;
    if (test[temp - 1])
    {
      cur -= list[temp - 1];
      test[temp - 1] = false;
    }
    else
    {
      cur += list[temp - 1];
      test[temp - 1] = true;
    }
    maks = max(maks, cur);
  }
  if (maks > c)
  {
    cout << "Sequence " << test1 << endl;
    cout << "Fuse was blown.\n";
  }
  else
  {
    cout << "Sequence " << test1 << endl;
    cout << "Fuse was not blown.\n";
    cout << "Maximal power consumption was " << maks << " amperes.\n";
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

  ll n, m, c;
  ll i = 0;
  while (cin >> n >> m >> c)
  {
    if (n == 0 && m == 0 && c == 0)
      break;
    // if (i != 0)
    //   cout << endl;
    solve(n, m, c, ++i);
    cout << endl;
  }
}