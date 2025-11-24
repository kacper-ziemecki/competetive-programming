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
  ll n,res=LLONG_MIN,cur;
  cin >> n;
  vector<vector<ll>> list(2*n, vector<ll>(2*n));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      cin >> list[i][j];
      res = max(res, list[i][j]);
      list[n+i][j] = list[i][j];
      list[i][n+j] = list[i][j];
      list[n+i][n+j] = list[i][j];
    }
  }
  for(ll i = 0; i < 2*n; i++){
    for(ll j = 0; j < 2*n; j++){
      list[i][j] += (j==0 ? 0 : list[i][j-1]);
    }
  }
  for(ll l = 0; l < n; l++){
    for(ll r = l; r < 2*n-(n-l); r++){
      for(ll rowStart = 0; rowStart < 2*n; rowStart++){
        cur=0;
        for(ll row = rowStart; row < min(rowStart+n,2*n); row++){
          cur += list[row][r] - (l==0 ? 0 : list[row][l-1]);
          if(cur < 0){
            cur=0;
          } else{
            res = max(res, cur);
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
  while(t--) solve();
}