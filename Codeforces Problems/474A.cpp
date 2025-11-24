#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  vector<string> test = { "qwertyuiop","asdfghjkl;","zxcvbnm,./" };
  char znak;
  cin >> znak;
  string text;
  cin >> text;
  if (znak == 'R') {
    for (auto el : text) {
      for (ll i = 0; i < test.size(); i++) {
        for (ll j = 0; j < test[0].size(); j++) {
          if (el == test[i][j]) {
            cout << test[i][j - 1];
          }
        }
      }
    }
  }
  else {
    for (auto el : text) {
      for (ll i = 0; i < test.size(); i++) {
        for (ll j = 0; j < test[0].size(); j++) {
          if (el == test[i][j]) {
            cout << test[i][j + 1];
          }
        }
      }
    }
  }
  cout << endl;
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