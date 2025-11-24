#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  ll l = 0, r = 0;
  ll maks = 0, minimum = INT_MAX;
  for(ll i = 1; i < n; i++){
    if(list[i-1] + 2 < list[i]){
      ll temp = r;
      r = i;
      l = temp;
      maks = max(maks, r-l);
      minimum = min(minimum, r-l);
    }
  }
  maks = max(maks, n-r);
  minimum = min(minimum, n-r);
  if(maks == 0){
    cout << n << " " << n << endl;
    return;
  }
  cout << minimum << " " << maks << endl;
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