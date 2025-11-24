#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ld n;
  cin >> n;
  ld res = 0;
  ld a,b,c;
  for(ll i = 0; i < n; i++){
    cin >> a >> b >> c;
    ld price = a;
    price += (price*(c/100.0));
    price -= (price*(c/100.0));
    res += (a*b) - (price*b);
  }
  cout << fixed << res << endl;
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