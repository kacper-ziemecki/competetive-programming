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
const ll maxn = 3001, mod = 998244353;
ll dp[maxn][maxn];

void solve(){
  cin >> n;
  vector<int> a(n), b(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(int i = a[0]; i <= b[0]; i++) dp[0][i] = 1;
  for(int i = 1; i < n; i++){
    ll prev = 0;
    for(int j = 0; j < a[i]; j++) prev = (prev+dp[i-1][j]) % mod;
    for(int j = a[i]; j <= b[i]; j++){
      prev = (prev+dp[i-1][j]) % mod;
      dp[i][j] = prev;
    }
  }
  ll res = 0;
  for(int i = a[n-1]; i <= b[n-1]; i++) res = (res+dp[n-1][i]) % mod;
  cout << res << endl;
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