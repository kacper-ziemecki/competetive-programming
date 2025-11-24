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
  ll a,b,c;
  ll res=LLONG_MIN,cur;
  cin >> a >> b >> c;
  vector<vector<vector<ll>>> list(a, vector<vector<ll>>(b, vector<ll>(c)));
  vector<vector<vector<ll>>> dp(a, vector<vector<ll>>(b, vector<ll>(c)));  
  for(ll i = 0; i < a; i++){
    for(ll j = 0; j < b; j++){
      for(ll k = 0; k < c; k++){
        cin >> list[i][j][k];
        res = max(res, list[i][j][k]);
      }
    }
  }
  for(ll i = 0; i < a; i++){
    for(ll j = 0; j < b; j++){
      for(ll k = 0; k < c; k++){
        dp[i][j][k] = list[i][j][k] + (k==0 ? 0 : dp[i][j][k-1]) + (j==0 ? 0 : dp[i][j-1][k]) - (k==0||j==0 ? 0 : dp[i][j-1][k-1]);
      }
    }
  }
  for(ll lc = 0; lc < c; lc++){
    for(ll rc = lc; rc < c; rc++){
      for(ll lb = 0; lb < b; lb++){
        for(ll rb = lb; rb < b; rb++){
          cur=0;
          for(ll row = 0; row < a; row++){
            cur += dp[row][rb][rc] - (lb==0 ? 0 : dp[row][lb-1][rc]) - (lc==0 ? 0 : dp[row][rb][lc-1]) + (lb==0||lc==0 ? 0 : dp[row][lb-1][lc-1]);
            if(cur < 0){
              cur = 0;
            } else{
              res = max(res, cur);
            }
          }
        }
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
  for(ll i = 0; i < t; i++){
    if(i!=0) cout << endl;
    solve();
  }
}