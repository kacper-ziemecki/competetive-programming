#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  vector<vector<ll>> list(3, vector<ll>(3, 0)), res(3, vector<ll>(3, 1));
  for (auto& sub : list) {
    for (auto& el : sub) {
      cin >> el;
      el %= 2;
    }
  }
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      if (list[i][j] == 1) {
        res[i][j] = 1 - res[i][j];
        if (i - 1 >= 0) res[i - 1][j] = 1 - res[i - 1][j];
        if (i + 1 < 3) res[i + 1][j] = 1 - res[i + 1][j];
        if (j - 1 >= 0) res[i][j - 1] = 1 - res[i][j - 1];
        if (j + 1 < 3) res[i][j + 1] = 1 - res[i][j + 1];
      }
    }
  }
  for (auto sub : res) {
    for (auto el : sub) cout << el;
    cout << endl;
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

  solve();
}