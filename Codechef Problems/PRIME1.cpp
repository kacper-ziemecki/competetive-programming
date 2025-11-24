#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,m;
  cin >> n >> m;
  bool flag = true;
  for(ll i = n; i <= m; i++){
    flag = true;
    if(i == 1) continue;
    for(ll j = 2; j*j <= i; j++){
      if(i%j == 0){
        flag = false;
        break;
      }
    }
    if(flag) cout << i << endl;
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