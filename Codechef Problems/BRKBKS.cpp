#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll s;
  cin >> s;
  vector<ll> list(3, 0);
  for(auto &el : list) cin >> el;

  if(list[0]+list[1]+list[2] <= s){
    cout << 1 << endl;
    return;
  }
  else if(list[0]+list[1] <= s){
    cout << 2 << endl;
    return;
  }
  else if(list[2]+list[1] <= s){
    cout << 2 << endl;
    return;
  }
  else{
    cout << 3 << endl;
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