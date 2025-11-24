#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int poczotek = 0, koniec = c, srodek, wynik = -1;
  while(poczotek <= koniec){
    srodek = (poczotek+koniec) / 2;
    if(srodek*a + (c-srodek)*b <= d){
      wynik = srodek;
      koniec = srodek - 1;
    }
    else{
      poczotek = srodek + 1;
    }
  }
  if(wynik != -1){
    cout << wynik << " " << c-wynik << endl;
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
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}