#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n, ll b, ll h, ll w)
{
  ll res = INT_MAX;
  ll p;
  ll a;
  for (ll i = 0; i < h; i++)
  {
    cin >> p;
    for (ll j = 0; j < w; j++)
    {
      cin >> a;
      if (a >= n)
      {
        res = min(res, n * p);
      }
    }
  }
  if (res <= b)
  {
    cout << res << endl;
  }
  else
  {
    cout << "stay home\n";
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

  ll n, b, h, w;
  while (cin >> n >> b >> h >> w)
    solve(n, b, h, w);
}