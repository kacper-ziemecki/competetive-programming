#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(3, 0);
  for (auto& el : list) cin >> el;
  if (list[n - 1] == 0) {
    cout << "NO\n";
  }
  else if (list[list[n - 1] - 1] == 0) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
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