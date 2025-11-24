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
  sort(list.begin(), list.end());
  map<ll, ll> mp;
  for(auto el : list) mp[el]++;
  ll cnt = 0;
  for(auto el : mp) if(el.second == 1) cnt++;
  if(list[n-1] != list[n-2] && cnt == 1){
    ll mx = LLONG_MIN;
    ll mn = LLONG_MAX;
    for(auto el : mp){
      if(el.second != 1){
        mx = max(mx, el.second);
        mn = min(mn, el.second);
      }
    }
    if(mx >= 3) cout << 1 << endl;
    else cout << mn << endl;
    return;
  }
  cout << (cnt+1)/2 << endl;
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