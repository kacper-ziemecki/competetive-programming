#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll test)
{
  cout << "Case " << test << ":";
  ll n;
  cin >> n;
  n++;
  vector<string> list(n, "");
  for (auto& el : list) cin >> el;
  for (ll i = 0; i < n - 1; i++) {
    ll temp = 0;
    for (ll j = 0; j < list[i].size();j++) {
      if (list[i][j] != list[n - 1][j]) temp++;
    }
    if (temp <= 1) {
      cout << endl << list[i];
    }
  }
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
    if (i != 1) cout << endl;
    solve(i);
  }
}