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
  ll b = 0;
  ll one=INT_MAX, two=INT_MAX;
  for(auto el : l){
    if(el&1) b++;

    if(el&1) one=min(one, el);
    else two = min(two, el);
  }
  if(b == 0 || b == n || two > one){
    cout << "YES\n";
  } else{
    cout << "NO\n";
  }
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