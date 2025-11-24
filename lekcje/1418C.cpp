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

ll n;
const ll maxN = 2e5+1;
ll lista[maxN], dp[maxN][2];

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> lista[i];
  dp[0][0] = 2e5+1;
  dp[0][1] = (lista[0] == 1 ? 1 : 0);
  for(ll i = 1; i < n; i++){
    dp[i][1] = min(dp[i-1][0]+(lista[i] == 1 ? 1 : 0), (i-2 >= 0 ? dp[i-2][0] : 0) +(lista[i] == 1 ? 1 : 0)+(lista[i-1] == 1 ? 1 : 0));
    dp[i][0] = min(dp[i-1][1], (i-2 >= 0 ? dp[i-2][1] : LLONG_MAX));
  }
  // for(ll i = 0; i < n; i++) cout << dp[i][0] << "|" << dp[i][1] << " , ";
  cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../in.in", "r", stdin);
  // freopen("../out.out", "w", stdout);

  ll t;
  cin >> t;
  while(t--)
  solve();

}