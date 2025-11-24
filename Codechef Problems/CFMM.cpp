#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<string> list(n, " ");
  for(auto &el : list) cin >> el;
  map<char, ll> mapa;  
  for(auto el : list){
    for(auto c : el){
      mapa[c]++;
    }
  }
  ll res = INT_MAX;
  string ans = "codechef";
  for(auto el : ans){
    ll temp = (el == 'c' || el == 'e' ? mapa[el]/2 : mapa[el]);
    res = min(res, temp);
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