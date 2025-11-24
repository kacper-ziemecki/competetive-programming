#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll a, ll b)
{
  ll res = abs(a - b);
  res = min(res, 99 - a + b + 1);
  res = min(res, 99 - b + a + 1);
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

  ll a, b;
  while (true)
  {
    cin >> a >> b;
    if (a == -1 && b == -1)
      break;
    solve(a, b);
  }
}