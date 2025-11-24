#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll n){
  ll res=LLONG_MIN;
  vector<vector<ll>> list(n, vector<ll>(n));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      cin >> list[i][j];
      res = max(res, list[i][j]);
      if(j>0) list[i][j] += list[i][j-1];
    }
  }
  for(ll l = 0; l < n; l++){
    for(ll r = l; r < n; r++){
      ll cur=0;
      for(ll row = 0; row < n; row++){
        if(l==0) cur += list[row][r];
        else cur += list[row][r] - list[row][l-1];
        if(cur < 0) cur = 0;
        else res = max(res, cur);
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
  ll n;
  while(cin>>n, !cin.eof())
  solve(n);
}