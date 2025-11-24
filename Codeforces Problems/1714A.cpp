#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, H, M;
  cin >> n >> H >> M;
  vector<pair<ll, ll>> list(n, { 0, 0 });
  for (auto& el : list) cin >> el.first >> el.second;
  ll res = LONG_LONG_MAX;
  ll time = H * 60 + M;
  for (auto el : list) {
    ll temp = el.first * 60 + el.second;
    if (temp < time) {
      res = min(res, 24 * 60 - (time - temp));
    }
    else {
      res = min(res, temp - time);
    }
  }
  ll hours = 0, minutes = 0;
  while (res >= 60) {
    res -= 60;
    hours++;
  }
  minutes += res;
  cout << hours << " " << minutes << endl;

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