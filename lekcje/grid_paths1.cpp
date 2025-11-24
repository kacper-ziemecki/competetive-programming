#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll int
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n, MOD=1e9+7;
  cin >> n;
  vector<vector<ll>> dp(n, vector<ll>(n));
  vector<string> lista(n);
  for(auto &el : lista) cin >> el;
  dp[0][0] = (lista[0][0] == '.' ? 1 : 0);
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(lista[i][j] == '*' || (i==0 && j==0)) continue;
      dp[i][j] = ((i-1 >= 0 ? dp[i-1][j] : 0) + (j-1 >= 0 ? dp[i][j-1] : 0))%MOD;

    }
  }
  cout << dp[n-1][n-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}