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
  vector<ll> a(n),b(n);
  vector<pair<ll,ll>> list(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(ll i = 0; i < n; i++) list[i] = {b[i]-a[i], i};
  sort(list.begin(), list.end(), greater<>());
  // for(auto el : list) cout << el.first << " " << el.second << endl;
  // cout << endl;
  vector<ll> res;
  for(ll i = n-1; i >= 0; i--){
    if(list[i].first != list.back().first) break;
    res.push_back(list[i].second+1);
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << " ";
  cout << endl;
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