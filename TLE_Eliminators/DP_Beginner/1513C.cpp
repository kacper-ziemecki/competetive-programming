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

string liczba;
ll m;
const ll maxm = 2e5+10;
ll dp[10][maxm];
ll occurances[10], res[10];
ll mod = 1e9+7;

void solve(){
  cin >> liczba >> m;

  for(int i = 0; i < 10; i++){
    occurances[i] = 0;
    res[i] = 0;
  }
  for(auto el : liczba) occurances[el-'0']++;

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      res[j] = (res[j] + dp[j][m+i]*occurances[i]) % mod;
    }
  }
  ll result = 0;
  for(int i = 0; i < 10; i++){
    result = (result + res[i]) % mod;
  }
  cout << result << endl;
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

  dp[0][0] = 1;
  for(int i = 1; i < maxm; i++){
    dp[0][i] = dp[9][i-1] % mod;
    dp[1][i] = (dp[9][i-1]+dp[0][i-1]) % mod;
    for(int j = 2; j < 10; j++){
      dp[j][i] = dp[j-1][i-1] % mod;
    }
  }

  int t;
  cin >> t;
  while(t--)
  solve();
}