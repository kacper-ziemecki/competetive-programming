#include <bits/stdc++.h>
using namespace std;




int main()
{
  int n;
  cin >> n;
  vector<int> lista(n,0);
  // for(int i = 0; i < n; i++) cin >> lista[i];
  for(auto &el : lista) cin >> el;

  //przykladowy input:
  //5 <--------- n
  //1 4 3 0 9
  //3 <--------- q
  //1 2 -> 7
  //0 3 -> 8
  //2 4 -> 12

  // n <= 100, q <= 1.000.000
  //rozwiozanie brutalne
  int q; 
  int l,r;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    int suma = 0;
    for(int j = l; j <= r; j++) suma += lista[j];
    cout << suma << endl;
  }

  // n,q <= 1.000.000
  //suma prefiksowa
  vector<int> pref(n);
  pref[0] = lista[0];
  for(int i = 1; i < n; i++) pref[i] = lista[i] + pref[i-1];
  // lista: 1 4 3 0 9
  // pref : 1 5 8 8 17
  int q; 
  int l,r;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    int suma = pref[r] - (l==0 ? 0 : pref[l-1]);
    cout << suma << endl;
  }
}