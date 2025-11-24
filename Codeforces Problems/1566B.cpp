#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  ll res = (text.back() == '0' ? 1 : 0);
  for (ll i = 0; i < text.size() - 1; i++)
  {
    if (text[i] == '0' && text[i + 1] == '1')
      res++;
  }
  cout << min(2ll, res) << endl;
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