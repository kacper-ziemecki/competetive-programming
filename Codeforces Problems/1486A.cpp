#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  ll suma = 0;
  ll res = 0;
  ll temp;
  bool flag = true;
  for (ll i = 0; i < n; i++) {
    res += i;
    cin >> temp;
    suma += temp;
    if (suma < res) {
      flag = false;
    }
  }
  if (flag) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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