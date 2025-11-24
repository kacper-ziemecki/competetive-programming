#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n;
const ll maxN = 501, maxSum = (501*502)/2, MOD = 1e9+7;
ll dp[maxN][maxSum];

ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll helper(ll coin, ll sum){
  if(coin == 0 && sum == 0) return 1;
  if(coin == 0 || sum < 0) return 0;
  if(dp[coin][sum] != -1) return dp[coin][sum];
  return dp[coin][sum] = (helper(coin-1, sum) + helper(coin-1, sum-coin)) % MOD;
}

void solve()
{
  cin >> n;
  if((n*(n+1)/2)&1){
    cout << 0 << endl;
    return;
  }
  for(ll i = 0; i <= n; i++){
    for(ll j = 0; j <= (n*(n+1))/2; j++){
      dp[i][j] = -1;
    }
  }
  cout << (helper(n, (n*(n+1))/4)*binpow(2, MOD-2)) % MOD << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}