#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b,c;
  cin >> a >> b >> c;
  if((a*b)%c == 0){
    cout << (a*b) << " " << c << endl;
  }
  else if((b*c)%a == 0){
    cout << (b*c) << " " << a << endl;
  }
  else if((c*a)%b == 0){
    cout << (c*a) << " " << b << endl;
  }
  else{
    cout << -1 << endl;
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