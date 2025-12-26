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

int n,k;
const ll maxn = 101, maxk = 1e5+1, mod = 1e9+7;
ll dp[maxn][maxk];
ll pref[maxn][maxk];
int lista[maxn];

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> lista[i];

  for(int i = 0; i <= k; i++){
    if(i <= lista[0]) dp[0][i] = 1;
    pref[0][i] = (i-1 < 0 ? 0 : pref[0][i-1]) + dp[0][i];
  }
  for(int id = 1; id < n; id++){
    for(int sum = 0; sum <= k; sum++){
      dp[id][sum] = ((pref[id-1][sum] - (sum-lista[id]-1 < 0 ? 0 : pref[id-1][sum-lista[id]-1])) + mod) % mod;
      pref[id][sum] = ((sum-1 < 0 ? 0 : pref[id][sum-1]) + dp[id][sum]) % mod;
    }
  }
  // for(int id = 0; id < n; id++){
  //   for(int sum = 0; sum <= k; sum++){
  //     cout << pref[id][sum] << ' ';
  //   }
  //   cout << endl;
  // }
  // for(int id = 0; id < n; id++){
  //   for(int sum = 0; sum <= k; sum++){
  //     cout << dp[id][sum] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << dp[n-1][k] << endl;
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