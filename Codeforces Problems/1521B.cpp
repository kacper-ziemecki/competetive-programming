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
  vector<vector<ll>> res;
  for(auto &el : list) cin >> el;
  ll idxMn=min_element(list.begin(), list.end())-list.begin(), mn=list[min_element(list.begin(), list.end())-list.begin()];
  for(ll i = 0; i < n; i++){
    if(i == idxMn) continue;
    if(abs(i-idxMn)&1) res.push_back({i+1, idxMn+1, mn+1, mn});
    else res.push_back({i+1, idxMn+1, mn, mn});
  }
  cout << res.size() << endl;
  for(ll i = 0; i < res.size(); i++){
    for(auto el : res[i]) cout << el << " ";
    cout << endl;
  }
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