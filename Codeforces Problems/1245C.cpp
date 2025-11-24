#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll MOD = 1000000007;
  string s;
  cin >> s;
  for(auto el : s){
    if(el == 'm' || el == 'w'){cout << 0 << endl; return;}
  }
  ll n = s.size();
  vector<ll> dp(n, 0);
  dp[0]=1;
  for(ll i = 1; i < n; i++){
    if(s[i]==s[i-1] && (s[i]=='n' || s[i]=='u')) dp[i] = dp[i-1] + (i-2>=0 ? dp[i-2] : 1ll);
    else dp[i] = dp[i-1];
    dp[i] %= MOD;
  }
  cout << dp[n-1] << endl;
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