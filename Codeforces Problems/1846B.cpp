#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  vector<string> l(3, " ");
  for(auto &el : l) cin >> el;
  for(ll i = 0; i < 3; i++){
    if(l[i][0] == l[i][1] && l[i][0] == l[i][2] && l[i][0] != '.'){
      cout << l[i][0] << endl;
      return;
    }
    if(l[0][i] == l[1][i] && l[0][i] == l[2][i] && l[0][i] != '.'){
      cout << l[0][i] << endl;
      return;
    }
  }
  if(l[0][0] == l[1][1] && l[0][0] == l[2][2] && l[0][0] != '.'){
    cout << l[0][0] << endl;
    return;
  }
  if(l[0][2] == l[1][1] && l[0][2] == l[2][0] && l[0][2] != '.'){
    cout << l[0][2] << endl;
    return;
  }
  cout << "DRAW\n";
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