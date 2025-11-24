#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll n, ll m){
  vector<vector<ll>> list(n, vector<ll>(m));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      cin >> list[i][j];
      list[i][j] += (j==0 ? 0 : list[i][j-1]);
    }
  }
  ll res=0,cur;
  for(ll l = 0; l < m; l++){
    for(ll r = l; r < m; r++){
      cur = 0;
      for(ll row = 0; row < n; row++){
        ll tmp = (r-l+1)-(list[row][r] - (l==0 ? 0 : list[row][l-1]));
        cur += tmp;
        if(tmp!=(r-l+1)) cur=0;
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
  
  ll n,m;
  while(cin>>n>>m,n!=0||m!=0) solve(n,m);
}