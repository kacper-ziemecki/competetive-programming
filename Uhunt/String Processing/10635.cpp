#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,p,q;
  cin >> n >> p >> q;
  p++;q++;
  vector<ll> a(p), b(q);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  vector<vector<ll>> dp(p+1, vector<ll>(q+1, 0));
  for(ll i = 1; i < p+1; i++){
    for(ll j = 1; j < q+1; j++){
      dp[i][j] = max({dp[i-1][j-1]+(a[i-1]==b[j-1]?1:-1000000), dp[i-1][j], dp[i][j-1]});
    }
  }
  cout << dp[p][q] << endl;
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
  
  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    cout << "Case " << i << ": ";
    solve();
  }
}