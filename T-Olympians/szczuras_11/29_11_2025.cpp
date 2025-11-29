#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// (a+b)/c
// (a+b+c-1)/c

// (lewo+prawo)/2
// (lewo+prawo+2-1)/2

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  int q;
  cin >> q;
  int v;
  while(q--){
    cin >> v;
    int lewo = 0, prawo = n-1;
    while(lewo < prawo){
      int srodek = (lewo+prawo+1)/2; // lewo = 5, prawo = 6, srodek = 6
      if(lista[srodek] < v) lewo = srodek; 
      else if(lista[srodek] >= v) prawo = srodek-1;
    }
    cout << prawo << endl;
  }
  // Codeforces zadanie 1 - podpowiedź
  for(int i = 0; i < k; i++){
    int v = tablica2[i];
    wyszukiwanie binarane na v
  }
}