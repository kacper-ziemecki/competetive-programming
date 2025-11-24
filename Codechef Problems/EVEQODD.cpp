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
  n*=2;
  vector<ll> list(n);
  ll even=0,odd=0;
  for(auto &el : list) cin >> el;
  for(auto el : list){
    if(el&1) odd++;
    else even++;
  }
  if(even <= odd){
    cout << abs(even-odd)/2 << endl;
  } else{
    vector<ll> ans;
    for(auto el : list){
      ll cnt=0;
      while(!(el&1)){
        cnt++;
        el >>= 1;
      }
      if(cnt) ans.push_back(cnt);
    }
    sort(ans.begin(), ans.end());
    ll res = 0;
    for(ll i = 0; i < abs(even-odd)/2; i++){
      res += ans[i];
    }
    cout << res << endl;
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