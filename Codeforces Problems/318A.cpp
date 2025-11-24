#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2) {
    cout << 1 + 2 * (k - 1) << endl;
  }
  else {
    cout << 2 * (k - ((n + 1) / 2)) << endl;
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