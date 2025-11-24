#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll test)
{
  ll n, m;
  cin >> n >> m;
  ll suma = 0;
  vector<ll> one(n, 0), two(n, 0);
  for (auto& el : one) cin >> el;
  for (auto& el : two) cin >> el;
  for (auto el : one) {
    suma += el;
  }
  if (suma > m) {
    cout << "Case " << test << ": No\n";
    return;
  }
  for (ll i = 0; i < n; i++) {
    if (one[i] > two[i]) {
      cout << "Case " << test << ": No\n";
      return;
    }
  }
  cout << "Case " << test << ": Yes\n";
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
  for (ll i = 1; i <= t; i++) {
    solve(i);
  }
}