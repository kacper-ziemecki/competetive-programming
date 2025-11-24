#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(ll test)
{
  string text;
  getline(cin, text);
  vector<string> list = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", " "};
  ll res = 0;
  for (auto el : text)
  {
    for (auto sub : list)
    {
      for (ll i = 0; i < sub.size(); i++)
      {
        if (el == sub[i])
          res += i + 1;
      }
    }
  }
  cout << "Case #" << test << ": " << res << endl;
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
  string smiec;
  getline(cin, smiec);
  for (ll i = 1; i <= t; i++)
    solve(i);
}