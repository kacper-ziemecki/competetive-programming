#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll x,y,a,b;
  cin >> x >> y >> a >> b;
  if((y-x)%(a+b) != 0){
    cout << -1 << endl;
    return;
  } 
  cout << (y-x)/(a+b) << endl;
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
  while(t--) solve();
}