#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;

  if (text == "1" || text == "4" || text == "78")
  {
    cout << "+\n";
    return;
  }
  else if (text.size() >= 3 && text[text.size() - 2] == '3' && text[text.size() - 1] == '5')
  {
    cout << "-\n";
    return;
  }
  else if (text.size() >= 3 && text[0] == '9' && text[text.size() - 1] == '4')
  {
    cout << "*\n";
    return;
  }
  else if (text.size() >= 4 && text[0] == '1' && text[1] == '9' && text[2] == '0')
  {
    cout << "?\n";
    return;
  }

  for (int i = 0; i < text.size(); i++)
  {
    if (i + 3 < text.size())
    {
      if (text[i] == '1' && text[i + 1] == '9' && text[i + 2] == '0')
      {
        cout << "?\n";
        return;
      }
    }
    if (i + 2 < text.size())
    {
      if (text[i] == '9' && text[i + 2] == '4')
      {
        cout << "*\n";
        return;
      }
    }
    if (i + 2 < text.size())
    {
      if (text[i + 1] == '3' && text[i + 2] == '5')
      {
        cout << "-\n";
        return;
      }
    }
    if (i + 1 < text.size())
    {
      if (text[i] == '7' && text[i + 1] == '8')
      {
        cout << "+\n";
        return;
      }
    }
    if (text[i] == '1' || text[i] == '4')
    {
      cout << "+\n";
      return;
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