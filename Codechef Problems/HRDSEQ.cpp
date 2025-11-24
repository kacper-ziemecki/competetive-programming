#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> res(n, 0);
  map<ll,vector<ll>> mapa;
  mapa[0] = {1};
  for(ll i = 1; i < n; i++){
    if(mapa[res[i-1]].size() == 1){
      mapa[0].push_back(i+1);
    }
    else{
      res[i] = i - mapa[res[i-1]][mapa[res[i-1]].size()-2];
      mapa[res[i]].push_back(i+1);
    }
  }
  cout << mapa[res[n-1]].size() << endl;
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