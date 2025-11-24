#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(11, 0);
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    list[temp]++;
  }
  // for(auto el : list) cout << el << " ";
  // cout << endl;
  map<ll, ll> mapa;
  for(ll i = 1; i < 11; i++){
    if(list[i] != 0) mapa[list[i]]++;
  }
  // for(auto el : mapa) cout << el.first << "->" << el.second << ", ";
  // cout << endl;
  ll res1 = 1;
  ll res2 = INT_MAX;
  for(auto el : mapa){
    if(el.second > res1){
      res1 = el.second;
      res2 = el.first;
    }
    else if(el.second == res1 && el.first < res2){
      res2 = el.first;
    }
  }
  cout << res2 << endl;
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