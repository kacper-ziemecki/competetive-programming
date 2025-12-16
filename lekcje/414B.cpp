#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const ll maxn = 2002;
ll dp[maxn][maxn];
vector<ll> divs[maxn];
ll n,k;
ll mod = 1e9+7;

void solve()
{
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j*j <= i; j++){
      if(i%j == 0){
        divs[i].pb(j);
        if(j != i/j) divs[i].pb(i/j);
      }
    }
  }
  for(ll i = 1; i <= n; i++) dp[i][1] = 1;
  for(ll num_of_elements = 2; num_of_elements <= k; num_of_elements++){
    for(ll cur = 1; cur <= n; cur++){
      dp[cur][num_of_elements] = 0;
      for(auto divisor : divs[cur]){
        dp[cur][num_of_elements] = (dp[cur][num_of_elements]+dp[divisor][num_of_elements-1]) % mod;
      }
    }
  }
  ll res = 0;
  for(ll i = 1; i <= n; i++){
    res = (res + dp[i][k]) % mod;
  }
  cout << res << endl;
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

  solve();

}