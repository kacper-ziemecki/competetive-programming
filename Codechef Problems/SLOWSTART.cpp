#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll x,h;
  cin >> x >> h;
  ll half = x/2;
  if(h <= half * 5){
    cout << (h+half-1)/half << endl;
  }
  else{
    h -= half * 5;
    cout << 5+((h+x-1)/x) << endl;
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