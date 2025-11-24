#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b;
  cin >> a >> b;
  ll rick = (b+9-1)/9;
  ll chef = (a+9-1)/9;
  if(rick <= chef){
    cout << 1 << " " << rick << endl;
  }
  else{
    cout << 0 << " " << chef << endl;
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