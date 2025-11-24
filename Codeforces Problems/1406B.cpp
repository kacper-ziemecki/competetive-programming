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
  for(auto &el : list) cin >> el;
  sort(list.rbegin(),list.rend());
  ll res = list[0] * list[1] * list[2] * list[n-1] * list[n-2];
  res = max(res, list[0] * list[n-4] * list[n-3] * list[n-1] * list[n-2]);
  res = max(res, list[0] * list[1] * list[2] * list[3] * list[4]);
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

  ll t;
  cin >> t;
  while(t--) solve();
}