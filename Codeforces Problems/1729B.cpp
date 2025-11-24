#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  string res = "";
  for (ll i = n - 1; i >= 0; i--) {
    if (text[i] == '0') {
      int temp = (text[i - 1] - '0') + (text[i - 2] - '0') * 10;
      res += char('a' + temp - 1);
      i -= 2;
    }
    else {
      int temp = (text[i] - '0');
      res += char('a' + temp - 1);
    }
  }
  reverse(res.begin(), res.end());
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

  ll t;
  cin >> t;
  while (t--) solve();

}