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

int n;
const int maxn = 2e3+1;
ll lista[maxn];
ll dp[maxn][maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  sort(lista, lista+n);
  for(int i = 2; i <= n; i++){
    for(int j = 0; j+i-1 < n; j++){
      dp[j][j+i-1] = lista[j+i-1]-lista[j]+min(dp[j+1][j+i-1],dp[j][j+i-2]);
    }
  }
  cout << dp[0][n-1] << endl;
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