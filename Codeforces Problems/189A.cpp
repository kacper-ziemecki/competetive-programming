#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<ll> dp(n+1,0);
  if(a <= n) dp[a]=1;
  if(b <= n) dp[b]=1;
  if(c <= n) dp[c]=1;

  ll one,two,three;
  for(ll i = 0; i <= n; i++){
    one = (i-a >= 0 && dp[i-a] != 0 ? dp[i-a]+1 : 0);
    two = (i-b >= 0 && dp[i-b] != 0 ? dp[i-b]+1 : 0);
    three = (i-c >= 0 && dp[i-c] != 0 ? dp[i-c]+1 : 0);
    dp[i] = max({dp[i],one,two,three});
  }
  cout << dp[n] << endl;
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();

}