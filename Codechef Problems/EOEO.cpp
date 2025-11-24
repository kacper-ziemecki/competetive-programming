#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll ts;
  cin >> ts;
  if(ts & 1){
    cout << ts / 2 << endl;
  }
  else{
    ll power = 1;
    ll tom = ts;
    while(!(tom & 1)){
      tom /= 2;
      power *= 2;
    }
    cout << tom / power << endl;
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
  while(t--)
  solve();
}