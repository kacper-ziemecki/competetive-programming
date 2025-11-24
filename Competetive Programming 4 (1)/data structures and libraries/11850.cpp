#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  vector<ll> list(n, 0);
  for (auto& el : list) cin >> el;
  sort(list.begin(), list.end());
  for (ll i = 1; i < n; i++) {
    if (list[i] - list[i - 1] > 200) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  if ((1422 - list[n - 1]) * 2 > 200) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << "POSSIBLE\n";
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

  ll n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    solve(n);
  }
}