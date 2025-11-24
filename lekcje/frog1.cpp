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
const ll maxN = 1e5+1;
ll h[maxN], dp[maxN];

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> h[i];
  for(ll i = 1; i < n; i++){
    dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), (i-2 >= 0 ? dp[i-2] + abs(h[i]-h[i-2]) : LLONG_MAX));
  }
  cout << dp[n-1] << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}