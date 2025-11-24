#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll i)
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for (auto &el : list)
    cin >> el;
  ll a = 0, b = 0;
  for (ll i = 1; i < n; i++)
  {
    if (list[i] > list[i - 1])
      a++;
    if (list[i] < list[i - 1])
      b++;
  }
  cout << "Case " << i << ": " << a << " " << b << endl;
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
  for (ll i = 1; i <= t; i++)
    solve(i);
}