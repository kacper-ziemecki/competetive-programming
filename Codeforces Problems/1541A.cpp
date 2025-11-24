#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  if (n & 1) {
    cout << "3 1 2 ";
    for (ll i = 4; i <= n; i++) {
      if (i & 1) {
        cout << i - 1 << " ";
      }
      else {
        cout << i + 1 << " ";
      }
    }
  }
  else {
    for (ll i = 1; i <= n; i++) {
      if (i & 1) {
        cout << i + 1 << " ";
      }
      else {
        cout << i - 1 << " ";
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


  ll t;
  cin >> t;
  while (t--) solve();
}