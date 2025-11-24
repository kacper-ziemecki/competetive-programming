#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n, ll m)
{
  vector<bool> list(n + 1, true);
  ll a, b, c, d;
  for (ll i = 0; i < m; i++) {
    cin >> a >> b;
    bool one = false, two = false;

    for (ll j = a; j <= min(b, n); j++) {
      list[j] = false;
    }

    for (ll j = a - 1; j >= 1; j--) {
      if (list[j]) {
        c = j;
        one = true;
        break;
      }
    }

    for (ll j = b + 1; j <= n; j++) {
      if (list[j]) {
        d = j;
        two = true;
        break;
      }
    }

    if (one) cout << c << " ";
    else cout << "* ";
    if (two) cout << d << " ";
    else cout << "* ";
    cout << endl;

  }
  cout << "-\n";
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

  ll n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    solve(n, m);
  }
}