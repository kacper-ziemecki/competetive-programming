#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  pair<ll, char> element = {n, 'R'};
  for (ll i = 0; i < n; i++)
  {
    if (text[i] == 'R' || text[i] == 'B')
    {
      element.first = i;
      element.second = text[i];
      break;
    }
  }
  ll j = 0;
  for (ll i = element.first - 1; i >= 0; i--)
  {
    j++;
    if ((element.second == 'R') && (j & 1))
    {
      text[i] = 'B';
    }
    else if ((element.second == 'R') && !(j & 1))
    {
      text[i] = 'R';
    }
    else if ((element.second == 'B') && (j & 1))
    {
      text[i] = 'R';
    }
    else if ((element.second == 'B') && !(j & 1))
    {
      text[i] = 'B';
    }
  }
  for (ll i = 1; i < n; i++)
  {
    if (text[i - 1] == 'R' && text[i] == '?')
    {
      text[i] = 'B';
    }
    if (text[i - 1] == 'B' && text[i] == '?')
    {
      text[i] = 'R';
    }
  }
  for (auto el : text)
    cout << el;
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
  while (t--)
    solve();
}