#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(ll m, map<ll, ll> &cnt){
  map<ll, ll> mp;
  for(ll i = 0; i < m; i++) mp[cnt[i]]++;
  // for(auto el : mp) cout << el.first << " -> " << el.second << endl;
  ll idx = 0;
  for(auto el : mp){
    idx += el.second;
    // dbg(el.first, idx, el.second, (el.first-1)*el.second);
    if((el.first-1)*el.second < idx-1) return false;
  }
  return true;
}

void solve(){
  ll n;
  cin >> n;
  vector<ll> list(n);
  map<ll, ll> cnt;
  for(auto &el : list) cin >> el;
  for(auto el : list) cnt[el]++;
  ll l = 0, r = 0;
  for(; r <= list[max_element(list.begin(), list.end()) - list.begin()]; r++){
    if(!cnt[r]) break;
  }
  // check(3, cnt);
  while(r-l > 0){
    ll m = (l+r+1)/2;
    // dbg(l, m, r);
    if(check(m, cnt)) l = m;
    else r = m-1;
  }
  cout << l << endl;
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
  while(t--) solve();
}