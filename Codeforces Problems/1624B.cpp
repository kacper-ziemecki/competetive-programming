#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if ((((b + (b - c)) > 0 && a > 0) || ((b + (b - c)) < 0 && a < 0)) && (b + (b - c)) % a == 0) {
    cout << "YES\n";
  }
  else if ((c - a) % 2 == 0 && ((((c - a) / 2 + a) > 0 && b > 0) || (((c - a) / 2 + a) < 0 && b < 0)) && ((c - a) / 2 + a) % b == 0) {
    cout << "YES\n";
  }
  else if ((b - a + b) % c == 0 && (((b - a + b) > 0 && c > 0) || ((b - a + b) < 0 && c < 0))) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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