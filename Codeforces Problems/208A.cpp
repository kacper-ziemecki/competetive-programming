#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  string res = "";
  string ans = "";
  for (ll i = 0; i < text.size(); i++) {
    if (i + 2 < text.size() && text[i] == 'W' && text[i + 1] == 'U' && text[i + 2] == 'B') {
      res += ' ';
      i += 2;
    }
    else {
      res += text[i];
    }
  }
  for (auto el : res) {
    if (el != ' ') ans += el;
    else if (ans.size() > 0 && ans.back() != ' ') {
      ans += el;
    }
  }
  cout << ans << endl;
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