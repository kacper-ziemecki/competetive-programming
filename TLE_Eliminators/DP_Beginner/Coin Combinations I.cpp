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
  int n,x,mod = 1e9+7;
  cin >> n >> x;
  vector<int> lista(n), dp(x+1);
  dp[0] = 1;
  for(auto &el : lista) cin >> el;
  for(int i = 1; i <= x; i++){
    for(auto el : lista){
      if(i-el < 0) continue;
      dp[i] = (dp[i] + dp[i-el]) % mod;
    }
  }
  cout << dp[x] << endl;
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