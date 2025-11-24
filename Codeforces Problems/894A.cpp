#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text, finalText;
  cin >> text;
  for (auto el : text)
  {
    if (el == 'Q' || el == 'A')
      finalText += el;
  }
  ll n = finalText.size();
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int x = j + 1; x < n; x++)
      {
        if (finalText[i] == 'Q' && finalText[j] == 'A' && finalText[x] == 'Q')
        {
          res++;
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
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}