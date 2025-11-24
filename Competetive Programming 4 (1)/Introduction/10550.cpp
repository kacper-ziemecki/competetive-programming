#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll a, ll b, ll c, ll d)
{
  ll res = 0;

  res += 360 * 3;
  res += (a - b < 0 ? a - b + 40 : a - b) * 9;
  res += (b - c < 0 ? abs(b - c) : abs(b - c - 40)) * 9;
  res += (c - d < 0 ? c - d + 40 : c - d) * 9;
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

  ll a, b, c, d;
  while (true)
  {
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
      break;
    solve(a, b, c, d);
  }
}