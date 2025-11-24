#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  if (text.size() == 5)
  {
    cout << 3 << endl;
  }
  if (text.size() == 3)
  {
    if ((text[0] == 'o' && text[1] == 'n') || (text[0] == 'o' && text[2] == 'e') || (text[1] == 'n' && text[2] == 'e'))
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 2 << endl;
    }
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}