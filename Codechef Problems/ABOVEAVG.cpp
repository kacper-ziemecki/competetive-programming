#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m,x;
  cin >> n >> m >> x;
  if(m < x){
    cout << n << endl;
  }
  else if(m == x){
    cout << 0 << endl;
  }
  else{
    cout << n - (n+m)/(m+1) << endl;
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