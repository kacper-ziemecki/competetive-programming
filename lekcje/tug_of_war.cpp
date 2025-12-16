#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
int n;
const int maxSuma = 100*100/4;
bitset<maxSuma> dp2[maxSuma];
bitset<maxSuma> dp1[maxSuma];
 
void solve()
{
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  if(n > 100){
    cout << "YES\n";
    return;
  }
  for(int i = 0; i < maxSuma; i++){
    dp1[i].reset();
    dp2[i].reset();
  }
  dp2[0][0] = 1;
  for(int id = 1; id <= n; id++){
    for(int suma1 = 0; suma1 < maxSuma; suma1++){
      dp1[suma1] = dp2[suma1] | (dp2[suma1] << lista[id-1]);
      if(suma1-lista[id-1] >= 0) dp1[suma1] |= dp2[suma1-lista[id-1]];
 
      // for(int suma2 = 0; suma2 < maxSuma; suma2++){
      //   dp1[suma]
      //   dp1[suma1][suma2] = dp2[suma1][suma2];
      //   if(suma1-lista[id-1] >= 0) dp1[suma1][suma2] |= dp2[suma1-lista[id-1]][suma2];
      //   if(suma2-lista[id-1] >= 0) dp1[suma1][suma2] |= dp2[suma1][suma2-lista[id-1]];
      // }
    }
    for(int suma1 = 0; suma1 < maxSuma; suma1++){
      // cout << dp1[suma1] << endl;
      // for(int suma2 = 0; suma2 < maxSuma; suma2++){
        dp2[suma1] = dp1[suma1];
      // }
    }
  }
  for(int suma = 1; suma < maxSuma; suma++){
    if(dp1[suma][suma]){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
  
 
int main()
{  
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//   freopen("../in.in", "r", stdin);
//   freopen("../out.out", "w", stdout);
// #endif
 
  int t;
  cin >>t;
  while(t--)
    solve();
 
} 