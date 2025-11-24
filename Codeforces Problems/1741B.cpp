#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll n;
  cin >> n;
  if(n&1){
    if(n == 3){
      cout << -1 << endl;
    } else{
      for(ll i = n; i > (n+1)/2; i--){
        cout << i << " ";
      }
      for(ll i = 1; i <= (n+1)/2; i++){
        cout << i << " ";
      }
      cout << endl;
    }
  } else{
    for(ll i = n; i > 0; i--){
      cout << i << " ";
    }
    cout << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
}