#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a == c && b == d){
    cout << 0 << endl;
  }
  else if((a+b)%2 != (c+d)%2){
    cout << 1 << endl;
  }
  else{
    cout << 2 << endl;
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