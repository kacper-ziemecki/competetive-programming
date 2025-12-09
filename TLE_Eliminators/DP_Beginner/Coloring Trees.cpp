#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m,k;
const ll mxL = 103;
ll cost[mxL][mxL];
ll dp[mxL][mxL][mxL];
ll lista[mxL];

ll helper(ll i, ll rest_k, ll prev){
  // dbg(i,rest_k,prev);
  if(rest_k < 0) return LLONG_MAX-1;
  if(i < 0) return (rest_k != 0 ? LLONG_MAX-1 : 0);
  if(dp[i][rest_k][prev] != LLONG_MAX) return dp[i][rest_k][prev];
  if(lista[i] != 0){ 
    // dbg(i);
    return dp[i][rest_k][prev] = helper(i-1, rest_k-(lista[i]-1==prev ? 0 : 1),lista[i]-1);
  }
  for(ll j = 0; j < m; j++){
    ll tmp = helper(i-1,rest_k-(j==prev ? 0 : 1),j);
    if(tmp == LLONG_MAX-1) dp[i][rest_k][prev] = min(dp[i][rest_k][prev], LLONG_MAX-1);
    else dp[i][rest_k][prev] = min(dp[i][rest_k][prev], helper(i-1,rest_k-(j==prev ? 0 : 1),j) + cost[i][j]);
  }
  // dbg(i,rest_k,prev,dp[i][rest_k][prev]);
  return dp[i][rest_k][prev];
}

void solve(){
  cin >> n >> m >> k;
  for(ll i = 0; i < n; i++) cin >> lista[i];
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++) cin >> cost[i][j];
  }
  for(ll i = 0; i < mxL; i++){
    for(ll j = 0; j < mxL; j++){
      for(ll x = 0; x < mxL; x++) dp[i][j][x] = LLONG_MAX;
    }
  }
  ll res = helper(n-1, k, m+1);
  cout << (res == LLONG_MAX-1 ? -1 : res)<< endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}