#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  getline(cin, text);
  ll one = 0, two = 0;

  for (ll i = 0; i < text.size(); i++)
  {
    if (text[i] == 'M')
    {
      one++;
    }
    if (text[i] == 'F')
    {
      two++;
    }
  }
  if (one == two && one > 1 && two > 1)
    cout << "LOOP\n";
  else
    cout << "NO LOOP\n";
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
  getline(cin, temp);
  while (t--)
    solve();
}