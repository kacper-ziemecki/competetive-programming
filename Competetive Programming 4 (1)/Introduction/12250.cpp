#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string text, ll i)
{
  if (text == "HELLO")
  {
    cout << "Case " << i << ": ENGLISH\n";
  }
  else if (text == "HOLA")
  {
    cout << "Case " << i << ": SPANISH\n";
  }
  else if (text == "HALLO")
  {
    cout << "Case " << i << ": GERMAN\n";
  }
  else if (text == "BONJOUR")
  {
    cout << "Case " << i << ": FRENCH\n";
  }
  else if (text == "CIAO")
  {
    cout << "Case " << i << ": ITALIAN\n";
  }
  else if (text == "ZDRAVSTVUJTE")
  {
    cout << "Case " << i << ": RUSSIAN\n";
  }
  else
  {
    cout << "Case " << i << ": UNKNOWN\n";
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

  ll i = 0;
  string text;
  while (true)
  {
    i++;
    cin >> text;
    if (text == "#")
      break;
    solve(text, i);
  }
}