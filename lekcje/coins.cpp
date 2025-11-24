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
const ll maxN = 3e3;
ld dp[maxN][maxN];
ld lista[maxN];

ld dynamic(ll id, ll sum){
  if(id < 0 || sum < 0) return 0;
  if(dp[id][sum] != -1) return dp[id][sum];
  return dp[id][sum] = (1-lista[id])*dynamic(id-1, sum) + lista[id]*dynamic(id-1, sum-1);
}

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> lista[i];

  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= n; j++) dp[i][j] = -1;
  }
  dp[0][0] = (1-lista[0]);
  dp[0][1] = lista[0];
  ld res=0;
  for(ll i = (n+1)/2; i <= n; i++){
    res += dynamic(n-1, i);
  }
  cout << fixed << setprecision(10) << res << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}