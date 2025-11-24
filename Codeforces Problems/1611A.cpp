#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  cin >> text;
  if (!((text.back() - '0') & 1)) {
    cout << 0 << endl;
    return;
  }
  else if (!((text.front() - '0') & 1)) {
    cout << 1 << endl;
    return;
  }
  for (auto el : text) {
    if (!((el - '0') & 1)) {
      cout << 2 << endl;
      return;
    }
  }
  cout << -1 << endl;
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