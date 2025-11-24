#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  ll n;
  cin >> n;
  vector<char> list(n, ' ');
  for (auto &el : list)
    cin >> el;
  ll temp = -1;
  for (ll i = 0; i < n; i++)
  {
    if (list[i] == 'W')
      temp = i;
    if (i - temp >= 3)
    {
      cout << "Case " << test << ": " << i + 1 << endl;
      return;
    }
  }
  cout << "Case " << test << ": "
       << "Yay! Mighty Rafa persists!" << endl;
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