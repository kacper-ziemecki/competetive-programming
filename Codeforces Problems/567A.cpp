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
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      cout << abs(list[0] - list[1]) << " " << abs(list[0] - list[n - 1]) << endl;
    }
    else if (i == n - 1) {
      cout << abs(list[n - 1] - list[n - 2]) << " " << abs(list[n - 1] - list[0]) << endl;
    }
    else {
      cout << min(abs(list[i] - list[i - 1]), abs(list[i] - list[i + 1])) << " " << max(abs(list[i] - list[0]), abs(list[i] - list[n - 1])) << endl;
    }
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

  solve();
}