#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll x,y,k,n;
  cin >> x >> y >> k >> n;
  x -= y;
  ll a,b;
  bool flag = false;
  for(ll i = 0; i < n; i++){
    cin >> a >> b;
    if(b <= k && a >= x){
      flag = true;
    }
  }
  if(flag) cout << "LuckyChef\n";
  else cout << "UnluckyChef\n";
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