#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n, m;
  cin >> n >> m;
  ll res = 0;
  for (int i = 0; i <= min(m, n); i++) {
    if (i * i + sqrt(m - i) == n && (n - i * i) * (n - i * i) + i == m) {
      res++;
    }
  }
  cout << res << endl;
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