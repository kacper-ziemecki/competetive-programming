#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(string text)
{
  vector<ll> list = { -1 };
  for (ll i = 0; i < text.size(); i++) {
    if (text[i] == 'X') list.push_back(i);
  }
  list.push_back((ll)text.size());
  ll res = max(list[1] - 1, (ll)text.size() - list[(ll)list.size() - 2] - 2);
  for (ll i = 1; i < list.size(); i++) {
    res = max(res, (list[i] - list[i - 1]) / 2 - 1);
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  string text;
  while (cin >> text) {
    solve(text);
  }
}