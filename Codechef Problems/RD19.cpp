#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  ll temp;
  cin >> temp;
  ll res = temp;
  for(ll i = 1; i < n; i++){
    cin >> temp;
    res = __gcd(res, temp);
  }
  if(res == 1){
    cout << 0 << endl;
  }
  else{
    cout << -1 << endl;
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