#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll k;
  cin >> k;
  k--;
  vector<string> list(8, "XXXXXXXX");
  list[0][0] = 'O';

  for(ll i = 0; i < 8; i++){
    for(ll j = 0; j < 8; j++){
      if(k == 0) break;
      if(list[i][j] == 'X'){
        list[i][j] = '.';
        k--;
        if(k == 0) break;
      }
    }
    if(k == 0) break;
  }
  for(auto el : list) cout << el << endl;
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