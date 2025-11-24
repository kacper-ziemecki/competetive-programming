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
  ll n,m,k;
  cin >> n >> m >> k;
  vector<vector<ll>> list(n, vector<ll>(m));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      cin >> list[i][j];
      list[i][j] += (j==0 ? 0 : list[i][j-1]);
    }
  }
  pair<ll,ll> res{LLONG_MAX,0}, cur;
  for(ll l = 0; l < m; l++){
    for(ll r = l; r < m; r++){
      cur={0,0};
      ll row1=0;
      for(ll row2 = 0; row2 < n; row2++){
        cur={cur.first+(list[row2][r]-(l==0?0:list[row2][l-1])),cur.second+(r-l+1)};
        while(cur.first > k && row1 <= row2){
          cur={cur.first-(list[row1][r]-(l==0?0:list[row1][l-1])), cur.second-(r-l+1)};
          row1++;
        }
        if(res.second < cur.second) res=cur;
        else if(res.second == cur.second && res.first > cur.first) res=cur;
      }
    }
  }
  cout << res.second << " " << res.first << endl;
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
  for(ll i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
}