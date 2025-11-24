#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll t){
  ll n;
  cin >> n;
  vector<ll> list(n-1);
  vector<pair<ll, ll>> ans;
  for(auto &el : list) cin >> el;
  ll l=0;
  ll res=0,cur=0;
  for(ll r = 0; r < n-1; r++){
    cur += list[r];
    if(cur < 0){
      l = r+1;
      cur = 0;
    }
    if(res < cur) ans.clear();
    if(res <= cur){
      ans.push_back({l,r});
      res = max(res, cur);
    }
  }
  if(res==0){
    cout << "Route " << t << " has no nice parts\n"; return;
  }
  ll mx=0;
  for(auto el : ans) mx = max(mx, (el.second+2) - (el.first+1));
  vector<pair<ll,ll>> ans1;
  for(auto el : ans){
    if((el.second+2)-(el.first+1) == mx) ans1.push_back({el.first+1, el.second+2});
  }
  cout << "The nicest part of route " << t << " is between stops " << ans1[0].first << " and " << ans1[0].second << endl;

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
  for(ll i = 1; i <= t; i++) solve(i);
}