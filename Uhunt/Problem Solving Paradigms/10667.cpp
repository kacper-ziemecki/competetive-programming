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
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> list(n, vector<ll>(n));
  ll r1,c1,r2,c2;
  for(ll i = 0; i < m; i++){
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;r2--;c1--;c2--;
    for(ll j = r1; j <= r2; j++){
      for(ll k = c1; k <= c2; k++) list[j][k]=1;
    }
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++) list[i][j] += (j==0 ? 0 : list[i][j-1]);
  }
  ll res=0,cur;
  for(ll l=0; l < n; l++){
    for(ll r=l; r < n; r++){
      cur=0;
      for(ll row=0; row < n; row++){
        ll tmp = list[row][r] - (l==0 ? 0 : list[row][l-1]);
        if(tmp){
          cur = 0; 
        } else{
          cur += (r-l+1);
          res = max(res, cur);
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