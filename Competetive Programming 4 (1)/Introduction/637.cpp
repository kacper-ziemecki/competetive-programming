#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll n)
{
  vector<vector<ll>> list(n, vector<ll>(4, 0));
  ll j = 0, k = n;
  for (ll i = 0; i < n; i++)
  {
    list[i][1] = ++j;
    list[i][2] = ++j;
    list[i][3] = k--;
    list[i][0] = k--;
  }
  for (auto sub : list)
  {
    for (auto el : sub)
    {
      cout << el << " ";
    }
    cout << endl;
  }
  cout << endl;
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
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;
    solve(n);
  }
}