#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  ll res = 0;
  ll test = 0;
  ll power = 1;
  for (ll i = 9; i > 0; i--) {
    if (n - test < i) {
      res += (n - test) * power;
      break;
    }
    else {
      res += i * power;
      test += i;
    }
    power *= 10;
  }
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