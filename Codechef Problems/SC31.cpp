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
  vector<ll> res(10, 0);
  for(auto el : list){
    for(ll i = 0; i < 10; i++){
      res[i] += (el[i] == '1' ? 1 : 0);
    }
  }
  ll ans = 0;
  for(auto el : res){
    if(el&1) ans++;
  }
  cout << ans << endl;
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