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
const ll maxN = 401;
ll lista[maxN], dp[maxN][maxN], pref[maxN];

ll sum(ll l, ll r){
  return pref[r] - (l-1 >= 0 ? pref[l-1] : 0);
}

ll helper(ll l, ll r){
  if(l == r) return dp[l][r] = 0;
  if(dp[l][r] != -1) return dp[l][r];

  dp[l][r] = LLONG_MAX;
  for(ll i = l; i < r; i++){
    dp[l][r] = min(dp[l][r], sum(l,i)+sum(i+1,r) + helper(l,i) + helper(i+1, r));
  }

  return dp[l][r];
}

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> lista[i];
  }  
  pref[0] = lista[0];
  for(ll i = 1; i < n; i++) pref[i] = lista[i] + pref[i-1];

  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) dp[i][j] = -1;
  }
  cout << helper(0, n-1) << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}