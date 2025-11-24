#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  cout << "Case " << test << ": ";
  vector<ll> res(100, 0);
  string text;
  getline(cin, text);
  ll pos = 0;
  for (auto el : text)
  {
    if (el == '>')
      pos++;
    if (el == '<')
      pos--;
    if (el == '+')
      res[pos]++;
    if (el == '-')
      res[pos]--;
    if (el == '.')
    {
      cout << res[pos] << " ";
    }
  }
  cout << endl
       << text << endl;
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

  ll t;
  cin >> t;
  string temp;
  for (ll i = 1; i <= t; i++)
  {
    if (i == 1)
      getline(cin, temp);
    solve(i);
  }
}