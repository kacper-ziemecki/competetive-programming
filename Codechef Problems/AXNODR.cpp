#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll res = 1;
  n--;
  if(n%4 == 1 || n%4 == 2){
    cout << 3 << endl;
    
  }
  else if(n%4 == 3){
    cout << 7 + 4*(n/4) << endl;
  }
  else{
    cout << 7 + 4*(n/4 - 1) - 2 << endl;
  }
  // n++;
  // cout << "-begin---\n";
  // for(ll i = 2; i <= n; i++){
  //   if(i&1){
  //     res &= i;
  //   }
  //   else{
  //     res ^= i;
  //   }
  //   cout << res << endl;
  // }
  // cout << "-end----\n";
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