#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> first(n, 0), second(n, 0);
  for (auto& el : first) cin >> el;
  for (auto& el : second) cin >> el;
  vector<pair<ll, ll>> list(n, { 0, 0 });
  for (ll i = 0; i < n; i++) {
    list[i] = { first[i], second[i] };
  }
  sort(list.begin(), list.end());
  for (auto el : list) {
    if (el.first <= k) {
      k += el.second;
    }
    else {
      break;
    }
  }
  cout << k << endl;
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