#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> s(n, 0ll), f(n, 0ll), res(n, 0ll);
  for(auto &el : s) cin >> el;
  for(auto &el : f) cin >> el;
  ll last = 0;
  for(ll i = 0; i < n; i++){
    last = max(s[i], last);
    res[i] = f[i] - last;
    last = f[i];
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}