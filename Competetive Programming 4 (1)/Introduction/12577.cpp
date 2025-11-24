#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string text, ll i)
{
  if (text == "Hajj")
  {
    cout << "Case " << i << ": Hajj-e-Akbar\n";
  }
  else
  {
    cout << "Case " << i << ": Hajj-e-Asghar\n";
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
  while (true)
  {
    i++;
    cin >> text;
    if (text == "*")
      break;
    solve(text, i);
  }
}