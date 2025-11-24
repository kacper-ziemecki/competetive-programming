#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (a == c && c == e) {
    if (max(b, d) > f && min(b, d) < f) {
      cout << max(b, d) - min(b, d) + 2 << endl;
    }
    else {
      cout << max(b, d) - min(b, d) << endl;
    }
  }
  else if (b == d && d == f) {
    if (max(a, c) > e && min(a, c) < e) {
      cout << max(a, c) - min(a, c) + 2 << endl;
    }
    else {
      cout << max(a, c) - min(a, c) << endl;
    }
  }
  else if (a == c && c != e) {
    cout << max(b, d) - min(b, d) << endl;
  }
  else if (b == d && d != f) {
    cout << max(a, c) - min(a, c) << endl;
  }
  else {
    cout << (max(a, c) - min(a, c)) + (max(b, d) - min(b, d)) << endl;
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
  while (t--) {
    solve();
  }
}