#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
void solve(){
  ll n,res=0;
  cin >> n;
  vector<ll> a(n),b(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 2; j++){
      dp[i][j] = (j==0 ? a[i] : b[i]) + max(i-1<0 ? 0 : dp[i-1][1-j], i-2<0 ? 0 : dp[i-2][1-j]);
      res = max(res, dp[i][j]);
    }
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