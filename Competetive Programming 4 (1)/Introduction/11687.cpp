#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string text)
{
  if (text == "1")
  {
    cout << 1 << endl;
    return;
  }
  ll res = 2;
  string temp = to_string(text.size());
  while (temp != "1")
  {
    temp = to_string(temp.size());
    res++;
  }
  cout << res << endl;
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
  while (true)
  {
    cin >> text;
    if (text == "END")
      break;
    solve(text);
  }
}