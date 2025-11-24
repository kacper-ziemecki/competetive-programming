#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve(ll n)
{
  vector<ll> list(n, 0);
  for (auto& el : list) cin >> el;
  ll res = 0;
  for (ll i = 1; i < n - 1; i++) {
    if (list[i] > list[i - 1] && list[i] > list[i + 1]) {
      res++;
    }
    if (list[i] < list[i - 1] && list[i] < list[i + 1]) {
      res++;
    }
  }
  if (list[0] > list[1] && list[0] > list[n - 1]) res++;
  if (list[0] < list[1] && list[0] < list[n - 1]) res++;
  if (list[n - 1] > list[0] && list[n - 1] > list[n - 2]) res++;
  if (list[n - 1] < list[0] && list[n - 1] < list[n - 2]) res++;
  cout << res << endl;
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