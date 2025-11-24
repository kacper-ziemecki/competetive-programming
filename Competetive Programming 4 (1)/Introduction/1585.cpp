#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  ll temp = (text[0] == 'O' ? 1 : 0);
  ll res = (text[0] == 'O' ? 1 : 0);
  for (ll i = 1; i < text.size(); i++)
  {
    if (text[i] == 'X')
      temp = -1;
    temp++;
    res += temp;
  }
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}