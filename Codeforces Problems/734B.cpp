#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll res = 0;
  while (a > 0 && c > 0 && d > 0) {
    a--;
    c--;
    d--;
    res += 256;
  }
  while (a > 0 && b > 0) {
    a--;
    b--;
    res += 32;
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

  solve();

}