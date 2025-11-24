#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for (auto& el : list) cin >> el;
  ll first = 0, last = 0;
  for (ll i = 0; i < n; i++) {
    if (list[i] == 1) {
      first = i;
      break;
    }
  }
  for (ll i = n - 1; i >= 0; i--) {
    if (list[i] == 1) {
      last = i;
      break;
    }
  }
  ll res = 0;
  for (ll i = first; i <= last; i++) {
    if (list[i] == 0) res++;
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