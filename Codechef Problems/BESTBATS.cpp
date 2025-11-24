#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

ll fact(ll n){
  ll res = 1;
  for(ll i = 2; i <= n; i++){
    res *= i;
  }
  return res;
}

void solve()
{
  vector<ll> list(11, 0);
  for(auto &el : list) cin >> el;
  ll k;
  cin >> k;
  sort(list.rbegin(), list.rend());
  map<ll, ll> mapa1, mapa2;
  for(auto el : list) mapa1[el]++;
  for(ll i = 0; i < k; i++){
    mapa2[list[i]]++;
  }
  ll res = 1;
  for(auto el : mapa2){
    // cout << el.first << " " << el.second << endl;
    res *= fact(mapa1[el.first]) / (fact(mapa1[el.first] - mapa2[el.first]) * fact(mapa2[el.first]));
  }
  cout << res << endl;
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