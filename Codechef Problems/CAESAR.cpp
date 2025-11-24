#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string a,b,c;
  cin >> a >> b >> c;
  ll shift = a[0] - b[0];
  for(auto &el : c){
    el -= shift;
    if(el < 'a'){
      el += 'z' - 'a' + 1;
    }
    else if(el > 'z'){
      el -= 'z' - 'a' + 1;
    }
  }
  cout << c << endl;
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