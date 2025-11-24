#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  ll sum = 0;
  ll res = 0;
  for (ll i = 0; i < text.size(); i++)
  {
    if (text[i] == '/')
      sum++;
    else if (text[i] == '\\')
    {
      sum--;
      ll temp = sum;
      for (ll j = i + 1; j < text.size(); j++)
      {
        if (text[j] == '/')
          temp++;
        else if (text[j] == '\\')
          temp--;

        if (temp == sum + 1)
        {
          res += j - i;
          break;
        }
      }
    }
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