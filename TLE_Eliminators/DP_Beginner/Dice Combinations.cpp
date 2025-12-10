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
  ll n,mod = 1e9+7;
  cin >> n;
  vector<ll> dp(n+1);
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = i-1; j >= max(0, i-6); j--){
      dp[i] = (dp[i] + dp[j]) % mod;
    }
  }
  cout << dp[n];
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