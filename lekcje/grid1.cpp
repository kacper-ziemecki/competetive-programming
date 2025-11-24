#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m;
const ll maxN = 1e3+1, MOD = 1e9+7;
string lista[maxN];
ll dp[maxN][maxN];

void solve()
{
  cin >> n >> m;
  for(ll i = 0; i < n; i++){
    cin >> lista[i];
  }  
  dp[0][0] = 1;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if((i==0&&j==0) || lista[i][j] == '#') continue;
      ll up = (i-1 >= 0 && lista[i-1][j] == '.' ? dp[i-1][j] : 0);
      ll left = (j-1 >= 0 && lista[i][j-1] == '.' ? dp[i][j-1] : 0);
      dp[i][j] = up+left;
      dp[i][j] %= MOD;
    } 
  }
  cout << dp[n-1][m-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}