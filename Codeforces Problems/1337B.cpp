#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a, b, c;
  cin >> a >> b >> c;
  while (b > 0) {
    ll temp = a / 2 + 10;
    if (temp >= a) break;
    a = temp;
    b--;
  }
  while (c > 0) {
    a -= 10;
    c--;
  }
  if (a <= 0) {
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