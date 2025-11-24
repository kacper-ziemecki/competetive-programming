#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve(ll n, ll m, string a, string b)
{
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  for(ll i = 1; i < n+1; i++) dp[i][0] = i;
  for(ll i = 1; i < m+1; i++) dp[0][i] = i;
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1, dp[i-1][j-1]+(a[i-1]==b[j-1]?0:10000)});      
    }
  }
  cout << dp[n][m] << endl;
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
  ll n,m;
  string a,b;
  while(cin >> n >> a >> m >> b) solve(n,m,a,b);
}