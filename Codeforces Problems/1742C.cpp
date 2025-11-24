#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  vector<string> list(8, " ");
  for (auto& el : list) cin >> el;
  ll i = -1;
  for (auto el : list) {
    i++;
    if (el == "RRRRRRRR") {
      cout << "R\n";
      return;
    }

    bool one = false, two = false, three = false;
    for (ll j = 0; j < 8; j++) {
      if (list[j][i] == 'R') {
        one = true;
      }
      else if (list[j][i] == 'B') {
        two = true;
      }
      else {
        three = true;
      }
    }


    if (one == false && two == true && three == false) {
      cout << "B\n";
      return;
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