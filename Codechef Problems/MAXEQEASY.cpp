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
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  map<ll, ll> mp;
  ll zeros=0, maks=0;
  for(auto el : list){
    if(el == 0) zeros++;
    else{
      mp[el]++;
      maks = max(maks, mp[el]);
    }
  }
  ll res = 0;
  bool flag = false;
  for(auto el : mp){
    if(maks == el.second && !flag){
      flag = true;
      res += ((el.second+zeros-1)*(el.second+zeros))/2;
    } else{
      res += ((el.second-1)*el.second)/2;
    }
  }
  if(mp.empty() && zeros >= 2) res += ((zeros-1)*zeros)/2;
  cout << res << endl;

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


  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}