#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string text, ll i)
{
  ll n;
  cin >> n;
  ll a, b;
  cout << "Case " << i << ":\n";
  for (ll i = 0; i < n; i++)
  {
    cin >> a >> b;
    bool flag = true;
    for (ll j = min(a, b); j <= max(a, b); j++)
    {
      if (text[j] != text[min(a, b)])
      {
        cout << "No\n";
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "Yes\n";
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

  string text;
  ll i = 0;
  while (cin >> text)
  {
    i++;
    solve(text, i);
  }
}