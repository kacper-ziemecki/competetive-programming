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
  vector<pair<ll,ll>> list1(n);
  vector<ll> suffix(n,0), list2(n);
  for(ll i = 0; i < n; i++){
    cin >> list1[i].first;
    list1[i].second = i+1;
  }
  sort(list1.begin(), list1.end());
  for(ll i = 0; i < n; i++) list2[i]=list1[i].first;
  if(list1.back().first < list1.back().second) suffix.back()=1;
  for(ll i = n-2; i >= 0; i--){
    suffix[i] = suffix[i+1] + (list1[i].first < list1[i].second);
  }
  // for(auto el : suffix) cout << el << " ";
  // cout << endl;
  ll res = 0;
  for(ll i = 0; i < n; i++){
    if(list1[i].first >= list1[i].second) continue;
    ll idx = upper_bound(list2.begin(), list2.end(), list1[i].second)-list2.begin();
    // dbg(list1[i].first, list1[i].second, idx);
    if(idx > n-1) continue;
    res += suffix[idx];
  }
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