#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b,n;
  cin >> a >> b >> n;
  if((a == b) || (a > b && a%b == 0) || (a < b && b%a == 0)){
    cout << -1 << endl;
    return;
  }
  ll res = 0;
  while(res < n || res%b == 0){
    res += a;
  }
  cout << res << endl;
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