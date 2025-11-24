#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll a,b;
  cin >> a >> b;
  if(a == 1 || b == 1){
    if(b == 2 || a == 2){
      cout << 3 << endl;
    }
    else{
      cout << 2 << endl;
    }
  }
  else{
    cout << 1 << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}