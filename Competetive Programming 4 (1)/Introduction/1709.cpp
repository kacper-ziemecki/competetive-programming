#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll p, ll a, ll b, ll c, ll d, ll n)
{
  vector<long double> list(n, 0), suffix(n, 0);
  for (ll i = 1; i <= n; i++)
  {
    double long temp = p * (sin(a * i + b) + cos(c * i + d) + 2);
    list[i - 1] = temp;
  }
  suffix[n - 1] = list[n - 1];
  for (ll i = n - 2; i >= 0; i--)
  {
    suffix[i] = min(suffix[i + 1], list[i]);
  }
  long double res = 0;
  for (ll i = 0; i < n - 1; i++)
  {
    res = max(res, list[i] - suffix[i + 1]);
  }
  cout.precision(15);
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

  ll p, a, b, c, d, n;
  while (cin >> p >> a >> b >> c >> d >> n)
    solve(p, a, b, c, d, n);
}