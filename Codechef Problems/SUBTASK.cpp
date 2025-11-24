#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,m,k;
  cin >> n >> m >> k;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll bad = n;
  for(ll i = 0; i < n; i++){
    if(list[i] == 0){
      bad = i;
      break;
    }
  }
  if(bad == n){
    cout << 100 << endl;
  }
  else if(bad < m){
    cout << 0 << endl;
  }
  else{
    cout << k << endl;
  }
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