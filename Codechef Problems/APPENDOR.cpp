#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,y;
  cin >> n >> y;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;

  ll res = 0;
  for(auto el : list) res |= el;

  if(res > y){
    cout << -1 << endl;
    return;
  }
  ll ans = 0;
  ll i = 0;
  // cout << res << endl;
  while((res|ans) != y){
    if(i == 64){
      cout << -1 << endl;
      return;
    }
    if((y>>i)&1 && !((res>>i)&1)){
      ans |= 1<<i;
    }
    i++;
    // cout << "ans: " << ans << endl;
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