#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  ll res = n;
  res *= 567.0;
  res /= 9.0;
  res += 7492.0;
  res *= 235.0;
  res /= 47.0;
  res -= 498.0;
  res -= res % 10;

  cout << abs((res % 100) / 10) << endl;
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