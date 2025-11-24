#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll conv[5] = {1, 5, 10, 25, 50};
ll dp[30001][5];

ll helper(ll n, ll i){
  if(n==0) return 1;
  if(i==5) return 0;
  if(dp[n][i] != -1) return dp[n][i];
  if(conv[i] > n) return dp[n][i] = helper(n, i+1);
  return dp[n][i] = helper(n, i+1)+helper(n-conv[i], i);
}

void solve(ll n){
  ll res = helper(n, 0);
  if(res==1){
    cout << "There is only 1 way to produce " << n << " cents change.\n";
  } else{
    cout << "There are " << res << " ways to produce " << n << " cents change.\n";
  } 
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

  for(ll i = 0; i < 30001; i++){
    for(ll j = 0; j < 5; j++) dp[i][j] = -1;
  }

  ll n;
  while(cin>>n){
    solve(n);
    if(cin.eof()) break;
  }
}