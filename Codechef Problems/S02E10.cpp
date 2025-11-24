#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,x,k;
  cin >> n >> x >> k;
  vector<ll> a(n, 0), b(n, 0);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    if(abs(a[i] - b[i]) <= k) res++;
  }
  if(res >= x){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}