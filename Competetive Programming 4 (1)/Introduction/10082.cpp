#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  string one = "`1234567890-=";
  string two = "QWERTYUIOP[]\\";
  string three = "ASDFGHJKL;'";
  string four = "ZXCVBNM,./";
  while (getline(cin, text))
  {
    string res = "";
    for (auto el : text)
    {
      if (el == ' ')
        cout << el;
      for (ll i = 1; i < one.size(); i++)
      {
        if (el == one[i])
        {
          cout << one[i - 1];
        }
      }
      for (ll i = 1; i < two.size(); i++)
      {
        if (el == two[i])
        {
          cout << two[i - 1];
        }
      }
      for (ll i = 1; i < three.size(); i++)
      {
        if (el == three[i])
        {
          cout << three[i - 1];
        }
      }
      for (ll i = 1; i < four.size(); i++)
      {
        if (el == four[i])
        {
          cout << four[i - 1];
        }
      }
    }
    cout << endl;
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

  solve();
}