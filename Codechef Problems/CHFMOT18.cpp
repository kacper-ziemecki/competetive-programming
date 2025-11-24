#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll s,n;
  cin >> s >> n;
  ll res = s/n;
  s -= s/n * n;
  if(s == 0){
    cout << res << endl;
  }
  else if(s == 1 || s%2 == 0){
    cout << res+1 << endl;
  }
  else{
    cout << res+2 << endl;
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