#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<pair<string, char>> list(n, {" ", ' '});
  for(auto &el : list) cin >> el.first >> el.second;
  map<string, char> mapa;
  for(auto el : list){
    mapa[el.first] = el.second;
  }
  ll res = 0;
  for(auto el : mapa){
    if(el.second == '+'){
      res++;
    }
    else{
      res--;
    }
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