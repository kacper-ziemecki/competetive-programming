#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ull conv[21];
ll dp[10001][21];

ull helper(ull n, ull i){
  if(n==0) return 1;
  if(i==21) return 0;
  if(dp[n][i] != -1) return dp[n][i];
  if(conv[i] > n) return dp[n][i] = helper(n, i+1);
  return dp[n][i] = helper(n, i+1)+helper(n-conv[i], i);
}

void solve(ull n){
  ull res = helper(n, 0);
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

  for(ll i = 0; i < 10001; i++){
    for(ll j = 0; j < 21; j++) dp[i][j] = -1;
  }
  for(ll i = 0; i < 21; i++) conv[i] = pow(i+1, 3);
  ull n;
  while(cin>>n){
    solve(n);
    if(cin.eof()) break;
  }
}