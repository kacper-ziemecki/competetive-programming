#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  vector<string> list(8, " ");
  for (auto& el : list) cin >> el;

  for (ll i = 1; i < 7; i++) {
    for (ll j = 1; j < 7; j++) {
      if (list[i][j] == '#' && list[i - 1][j - 1] == '#' && list[i - 1][j + 1] == '#' && list[i + 1][j + 1] == '#' && list[i + 1][j - 1] == '#') {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
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