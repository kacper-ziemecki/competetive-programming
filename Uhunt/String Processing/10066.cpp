#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll score(ll a, ll b){
  if(a == b) return 1;
  return -10000;
}

void solve(ll n, ll m)
{
  vector<ll> a(n), b(m);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
  for(ll i = 1; i < n+1; i++){
    for(ll j = 1; j < m+1; j++){
      dp[i][j] = max({dp[i-1][j-1]+score(a[i-1], b[j-1]), dp[i-1][j], dp[i][j-1]});
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
  ll t=0;
  while(cin >> n >> m, n != 0 || m != 0){
    cout << "Twin Towers #" << ++t << endl;
    cout << "Number of Tiles : ";
    solve(n,m);
    cout << endl;
  }
}