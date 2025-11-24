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

ll n,w;
const ll maxW = 1e5+1, maxN= 101;
ll dp[maxN][maxW];
pair<ll, ll> lista[maxN];

ll helper(ll i, ll rest){
  if(i < 0 || rest == 0) return 0;
  if(dp[i][rest] != -1) return dp[i][rest];
  if(lista[i].first > rest) return dp[i][rest] = helper(i-1, rest);
  return dp[i][rest] = max(helper(i-1, rest), lista[i].second + helper(i-1, rest-lista[i].first));
}
void solve()
{
  cin >> n >> w;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j <= w; j++){
      dp[i][j] = -1;
    }
  }
  for(ll i = 0; i < n; i++) cin >> lista[i].first >> lista[i].second;
  helper(n-1, w);
  cout << dp[n-1][w] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}