#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
bool simulate(ll k, vector<pair<ll, ll>> list){
  ll n = list.size();
  pair<ll, ll> para = {0, 0};
  for(ll i = 0; i < n; i++){
    para.first = max(para.first - k, list[i].first);
    para.second = min(para.second + k, list[i].second);
    if(para.first > list[i].second || para.second < list[i].first){
      return false;
    }
  }
  return true;
}
 
void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> list(n, {0, 0});
  ll maks = 0;
  for(auto &el : list) cin >> el.first >> el.second;
  for(auto el : list) maks = max({maks, el.second, el.first});
  ll l = 0, r = maks;
  while(l < r){
    ll m = (l+r)/2;
    if(simulate(m, list)){
      r = m;
    } else{
      l = m+1;
    }
  }
  cout << l << endl;
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
  while(t--)
  solve();
}