#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a, b;
  cin >> a >> b;
  for (ll i = 1;;i++) {
    if (a <= 0) {
      cout << i - 1 << endl;
      return;
    }
    a--;
    if (i % b == 0) a++;
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