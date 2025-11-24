#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll c,d,l;
  cin >> c >> d >> l;
  ll maks = c*4+d*4;
  ll minimum = d*4+max(0ll, c-d*2)*4;
  if(l <= maks && l >= minimum && l%4 == 0){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
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