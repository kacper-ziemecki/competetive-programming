#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll n,x;
  cin >> n >> x;
  n *= 2;
  vector<ll> l(n, 0ll);
  for(auto &el : l) cin >> el;
  sort(l.begin(), l.end());
  for(ll i = 0; i < n/2; i++){
    if(l[i+n/2]-x < l[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
  while(t--)
  solve();
}