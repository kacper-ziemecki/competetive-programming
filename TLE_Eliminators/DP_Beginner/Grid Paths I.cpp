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


void solve(){
  int n,mod = 1e9+7;
  cin >> n;
  vector<string> lista(n);
  for(auto &el : lista) cin >> el;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  // dbg(n);
  if(lista[0][0] == '*'){
    cout << 0 << endl;
    return;
  }
  dp[0][0] = 1;
  for(auto &el : lista) cin >> el;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(lista[i][j] == '*') continue;
      dp[i][j] = (dp[i][j] + (i-1 < 0 ? 0 : dp[i-1][j]) + (j-1 < 0 ? 0 : dp[i][j-1])) % mod;
    }
  }
  cout << dp[n-1][n-1] << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}