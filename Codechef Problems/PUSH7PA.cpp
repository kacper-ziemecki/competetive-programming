#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  map<ll, ll> mapa;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    mapa[temp]++;
  }
  ll res = 0;
  for(auto el : mapa){
    res = max(res, el.first + el.second - 1);
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
  while(t--)
  solve();
}