#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll k)
{
  ll n, m;
  cin >> n >> m;
  ll a, b;
  for (ll i = 0; i < k; i++)
  {
    cin >> a >> b;
    if (a == n || b == m)
    {
      cout << "divisa\n";
    }
    else if (a > n && b > m)
    {
      cout << "NE\n";
    }
    else if (a > n && b < m)
    {
      cout << "SE\n";
    }
    else if (a < n && b > m)
    {
      cout << "NO\n";
    }
    else
    {
      cout << "SO\n";
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

  ll k;
  while (cin >> k)
    solve(k);
}