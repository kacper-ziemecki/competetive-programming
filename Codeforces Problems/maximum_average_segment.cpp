#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

pair<bool, pair<ld,ld>> check(vector<ld>& list, ld n, ld d, ld mid){
  vector<ld> prefix(n);
  vector<pair<ld, ld>> minimum(n, {LDBL_MAX, 0});
  for(auto &el : list) el -= mid;
  for(ll i = 0; i < n; i++) prefix[i] = list[i] + (i?prefix[i-1]:0);
  for(ll i = 0; i < n; i++){
    if(prefix[i] < (i?minimum[i-1].first:LDBL_MAX)){
      minimum[i] = {prefix[i], i};
    } else{
      minimum[i] = {(i?minimum[i-1].first:LDBL_MAX), (i?minimum[i-1].second:0)};
    }
  }
  // for(ll i = 0; i < n; i++){
  //   cout << prefix[i] << " ";
  // }
  // cout << endl;
  // for(ll i = 0; i < n; i++){
  //   cout << minimum[i].first << " " << minimum[i].second << endl;
  // }
  for(auto &el : list) el += mid;
  for(ll i = d-1; i < n; i++){
    if(prefix[i] - (i-d < 0 ? 0 : minimum[i-d].first) >= 0) return {true, {(i-d < 0 ? 1 : minimum[i-d].second+2), i+1}};
  }
  return {false, {0,0}};
}

void solve()
{
  ld n,d;
  cin >> n >> d;
  vector<ld> list(n);
  for(auto &el : list) cin >> el;
  ld l = -10, r = 1e5, eps = 1e-12;
  pair<ld,ld> res = {1, n};
  while(l+eps<r){
    ld mid = (l+r)/2.0;
    pair<bool, pair<ld,ld>> ans = check(list,n,d,mid);
    dbg(l,mid,r, ans.first);
    if(ans.first){
      l = mid;
      res = ans.second;
    }
    else r = mid;
  }
  // cout << l << endl;
  cout << res.first << " " << res.second << endl;
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