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

ll n,k;
const int maxn = 5e3+1;
ll dp[maxn][maxn];
ll lista[maxn], hot[maxn], cold[maxn];
ll jeden,dwa;
ll mn1,mn2;

void solve(){
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < k; i++) cin >> cold[i];
  for(int i = 0; i < k; i++) cin >> hot[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= k; j++) dp[i][j] = 1e15;
  }
  dp[0][0] = cold[lista[0]-1];
  mn2 = cold[lista[0]-1];
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= k; j++){
      if(lista[i-1] == lista[i]){ // zwykle kopiowanie calosci
        dp[i][j] = min(dp[i][j], dp[i-1][j] + hot[lista[i]-1]);
      } else{ // zwykle kopiowanie calosci
        dp[i][j] = min(dp[i][j], dp[i-1][j] + cold[lista[i]-1]);
      }
      if(j == lista[i]){ // jest tylko jeden element i tez zwykle kopiowanie
        dp[i][lista[i-1]] = min(dp[i][lista[i-1]], dp[i-1][j] + hot[lista[i]-1]);
      } else{
        dp[i][lista[i-1]] = min(dp[i][lista[i-1]], dp[i-1][j] + cold[lista[i]-1]);
      }
    }
  }
  ll res = LLONG_MAX;
  for(int i = 0; i <= k; i++) res = min(res,dp[n-1][i]);
  cout << res << endl;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}