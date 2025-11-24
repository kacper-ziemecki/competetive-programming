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
  ll suma = 0;
  for(auto el : list) suma += el;
  pair<ll, ll> res = {LONG_LONG_MAX, LONG_LONG_MAX};
  for(ll i = 0; i < n; i++){
    if(res.first > suma + list[i]){
      res = {suma + list[i], i+1};
    }
  }
  cout << res.second << endl;
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