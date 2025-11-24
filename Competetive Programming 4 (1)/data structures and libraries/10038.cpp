#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  vector<ll> list(n, 0);
  vector<bool> test(n, false);
  for (auto &el : list)
    cin >> el;
  for (ll i = 1; i < n; i++)
  {
    if (abs(list[i - 1] - list[i]) < n)
      test[abs(list[i - 1] - list[i])] = true;
  }
  bool ans = true;
  for (ll i = 1; i < n; i++)
  {
    if (test[i] != true)
    {
      ans = false;
      break;
    }
  }
  if (ans)
  {
    cout << "Jolly\n";
  }
  else
  {
    cout << "Not jolly\n";
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

  ll n;
  while (cin >> n)
    solve(n);
}