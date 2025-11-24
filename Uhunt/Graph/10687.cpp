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
  vector<pair<ld, ld>> list(n);
  map<pair<ld, ld>, vector<pair<ld, ld>>> adj;
  for(auto &el : list) cin >> el.first >> el.second;
  for(ll i = 0; i < n; i++){
    ld dist1 = LDBL_MAX, dist2 = LDBL_MAX;
    pair<ll, ll> one,two;
    for(ll j = 0; j < n; j++){
      if(i==j) continue;
      ld curdist = sqrt((list[i].first-list[j].first)*(list[i].first-list[j].first) + (list[i].second-list[j].second)*(list[i].second-list[j].second));
      pair<ll, ll> cur = list[j];
      if(curdist < dist1){
        dist2 = dist1;
        two = one;
        dist1 = curdist;
        one = cur;
      }
    }
  }
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
  while(cin >> n, n != 0){
    solve(n);
  }
}