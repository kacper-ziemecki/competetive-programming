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
  vector<string> list;
  while(getline(cin, s), !s.empty()){
    list.push_back(s);
    if(cin.eof()) break;
  }
  ll n = list.size(), m = list[0].size();
  vector<vector<ll>> dp(n, vector<ll>(m));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      dp[i][j] = (list[i][j]-'0') + (j > 0 ? dp[i][j-1] : 0);
    }
  } 
  // for(ll i = 0;i < n; i++){
  //   for(ll j = 0; j < m; j++) cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  ll res=0,cur;
  for(ll l = 0; l < m; l++){
    for(ll r = l; r < m; r++){
      cur=0;
      for(ll row = 0; row < n; row++){
        ll tmp = dp[row][r] - (l==0 ? 0 : dp[row][l-1]); 
        cur += tmp;
        if(tmp < r-l+1) cur = 0;
        res = max(res, cur);
      }
    }
  }
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
  
  ll t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  for(ll i = 1; i <= t; i++){
    if(i!=1) cout << endl;
    solve();
  }
}