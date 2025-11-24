#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  set<ll> list;
  ll temp;
  for (ll i = 0; i < n; i++) {
    cin >> temp;
    list.emplace(temp);
  }
  if (n - list.size() & 1) {
    cout << list.size() - 1 << endl;
  }
  else {
    cout << list.size() << endl;
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