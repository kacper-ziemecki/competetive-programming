#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(m, 0));
  ll total = 0;
  for(auto &sub : list){
    for(auto &el : sub){
      cin >> el;
      total += el;
    }
  }
  ll res = 0;
  for(auto sub : list){
    for(auto el : sub){
      res = max(res, el ^ (total-el));
      cout << (el ^ (total-el)) << endl;
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
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}