#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll n;
  cin >> n;
  vector<ll> l(n, 0ll);
  for(auto &el : l) cin >> el;
  sort(l.begin(), l.end());
  ll res = 0;
  for(ll i = 1; i < n; i+=2){
    res += l[i] - l[i-1];
  }
  cout << res << endl;
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

  solve();
}