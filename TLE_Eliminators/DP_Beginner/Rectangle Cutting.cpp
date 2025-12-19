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

const int maxn = 501;
ll dp[maxn][maxn];
int n,m;

ll helper(int n, int m){
  if(n == m) return 0;
  if(dp[n][m] != LLONG_MAX) return dp[n][m];
  for(int i = 1; i < n; i++){
    dp[n][m] = min(dp[n][m], helper(i,m) + helper(n-i,m) + 1);
  }
  for(int i = 1; i < m; i++){
    dp[n][m] = min(dp[n][m], helper(n,i) + helper(n,m-i) + 1);
  }
  return dp[n][m];
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++) dp[i][j] = LLONG_MAX;
  }
  cout << helper(n,m) << endl;
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