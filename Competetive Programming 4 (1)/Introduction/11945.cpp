#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll test)
{
  ld sum = 0;
  ld temp;
  for (ll i = 0; i < 12; i++) {
    cin >> temp;
    sum += temp;
  }
  sum /= 12;
  cout << test << " $";
  string res1 = to_string(sum), res2, res3;
  ll one = -1;
  for (auto el : res1) {
    res2 += el;
    if (el == '.') {
      one++;
    }
    else if (one > -1) one++;
    if (one > 1) {
      break;
    }
  }
  if (one == -1) {
    res2 += ".00";
  }
  else if (one == 0) {
    res2 += "00";
  }
  else if (one == 1) {
    res2 += "0";
  }

  cout << res2 << endl;
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

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++)
    solve(i);
}