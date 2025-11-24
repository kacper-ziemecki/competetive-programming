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
  string s;
  cin >> s;
  ll n = s.size();
  vector<ll> dp(n,0);
  map<char, ll> mp;
  dp[0]=1;
  mp[s[0]]=1;
  ll mx=0;
  for(ll i = 1; i < n; i++){
    dp[i]=max(mp[s[i]]+1, (dp[i-1]&1 ? dp[i-1] : dp[i-1]+1));
    mp[s[i]]=dp[i];
    if(!(dp[i]&1)) mx = max(mx, dp[i]);
  }
  cout << n-mx << endl;
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
  
  ll t;
  cin >> t;
  while(t--)
  solve();
  
}