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
  vector<ll> list;
  ll a,cnt=0;
  while(cin>>a, a!=-999999) list.push_back(a);
  if(list.empty()) return;
  // for(auto el : list) cout << el << " ";
  // cout << endl;
  vector<vector<ll>> list1;
  for(ll i = 0; i < list.size(); i++){
    if(list[i] != 0 && (i==0 || (i>0 && list[i-1] == 0))){
      list1.push_back({});
    } 
    if(list[i] != 0){
      list1.back().push_back(list[i]);
    } else cnt++;
  }
  ll res = LLONG_MIN;
  for(auto sub : list1){
    ll cur = sub.front();
    for(ll i = 1; i < sub.size(); i++){
      res = max(res, cur);
      cur *= sub[i];
    }
    res = max(res, cur);
    cur = sub.back();
    for(ll i = sub.size()-2; i >= 0; i--){
      res = max(res, cur);
      cur *= sub[i];
    }
    res = max(res, cur);
  }
  if(cnt > 0) res = max(res, 0ll);
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
  
  
  while(!cin.eof()) solve();
}