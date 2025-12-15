#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
const int maxn = 102;
const int maxSuma = 100*100/2;
bool dp[maxn][maxSuma][maxSuma];

void solve()
{
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  if(n > 100){
    cout << "YES\n";
    return;
  }
  dp[0][0][0] = 1;
  for(int id = 1; id <= n; id++){
    for(int suma1 = 0; suma1 <= maxSuma; suma1++){
      for(int suma2 = 0; suma2 <= maxSuma; suma2++){
        dp[id][suma1][suma2] = dp[id-1][suma1][suma2];
        if(suma1-lista[id-1] >= 0) dp[id][suma1][suma2] |= dp[id-1][suma1-lista[id-1]][suma2];
        if(suma2-lista[id-1] >= 0) dp[id][suma1][suma2] |= dp[id-1][suma1][suma2-lista[id-1]];
      }
    }
  }
  for(int suma = 1; suma <= maxSuma; suma++){
    if(dp[n][suma][suma]){
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

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  int t;
  cin >>t;
  while(t--)
    solve();

}