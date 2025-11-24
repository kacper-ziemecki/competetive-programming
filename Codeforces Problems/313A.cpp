#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  if (n >= 0) {
    cout << n << endl;
  }
  else {
    ll one = abs(n) % 10;
    ll two = (abs(n) / 10) % 10;
    if (one >= two) {
      cout << n / 10 << endl;
    }
    else {
      cout << (n / 100) * 10 - one << endl;
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