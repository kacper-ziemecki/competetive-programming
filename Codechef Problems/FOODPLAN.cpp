#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ld a,b;
  cin >> a >> b;
  if(0.9 * a < b){
    cout << "ONLINE\n";
  }
  else if(0.9 * a > b){
    cout << "DINING\n";
  }
  else{
    cout << "EITHER\n";
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