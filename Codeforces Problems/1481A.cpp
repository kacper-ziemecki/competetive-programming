#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long


void solve()
{
  ll a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  ll one=0,two=0,three=0,four=0;
  for(auto el : s){
    if(el == 'U') one++;
    if(el == 'D') two++;
    if(el == 'R') three++;
    if(el == 'L') four++;
  }
  if((a >= 0 && a > three) || (a <= 0 && -a > four)){
    cout << "NO\n";
  } else if((b >= 0 && b > one) || (b <= 0 && -b > two)){
    cout << "NO\n";
  } else{
    cout << "YES\n";
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