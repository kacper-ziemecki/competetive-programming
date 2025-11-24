#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll d,c,a1,a2,a3,b1,b2,b3;
  cin >> d >> c >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
  ll suma1 = a1 + a2 + a3;
  ll suma2 = b1 + b2 + b3;
  ll normal = suma1 + d + suma2 + d;
  ll cupon = suma1 + (suma1 >= 150 ? 0 : d) + suma2 + (suma2 >= 150 ? 0 : d) + c;
  if(cupon < normal){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
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